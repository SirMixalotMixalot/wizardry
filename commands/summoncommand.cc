#include "summoncommand.h"
#include "game.h"
#include "player.h"
#include "minion.h"
#include "card_factory.h"

SummonCommand::SummonCommand(const std::string& minionName, int minionCount) : minionName(minionName), minionCount(minionCount) {}

void SummonCommand::execute(Game& game) {
    Player* activePlayer = game.getActivePlayer();
    vector<unique_ptr<Minion>> newMinions;

    // Make sure that the player's board is not full
    if (activePlayer->getBoard()->getSize() >= 5) {
        throw std::runtime_error("Player's board is full. Cannot summon more minions.");
    }

    for (int i = 0; i < minionCount; i++) {
        unique_ptr<Card> card = CardFactory::createCard(minionName, activePlayer);
        if (!card) {
            throw std::runtime_error("Failed to create minion: " + minionName);
        }

        Minion* minion = dynamic_cast<Minion*>(card.get());
        if (!minion) {
            throw std::runtime_error("Card is not a minion: " + minionName);
        }

        card.release();
        newMinions.push_back(unique_ptr<Minion>(minion));
    }

    // Place minions on active player's board until the board is full or all minions are summoned.
    for (auto& minion : newMinions) {
        if (activePlayer->getBoard()->getSize() < 5) {
            Minion* minionPtr = minion.get(); // Store raw pointer before move
            activePlayer->getBoard()->addCard(move(minion));
            game.setLastPlayedMinion(minionPtr);
            game.trigger(Triggers::MINION_ENTERS_PLAY);
        } 
        else {
            break; // Stop adding if the board is full
        }
    }
}