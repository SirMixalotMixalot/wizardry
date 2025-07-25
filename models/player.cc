#include "player.h"
#include "minion.h"
#include <iostream>
#include "enchantment.h"
#include "spell.h"
#include <stdexcept>
#include <memory>
#include <applyenchantmentcommand.h>
using namespace std;

Player::Player(const string& name, const string& deckFile, Game* game) : name(name), magic(3), health(20), game(game) {
    deck = make_unique<Deck>(deckFile, this);
    hand = make_unique<Hand>();
    board = make_unique<Board>();
    graveyard = make_unique<Graveyard>();
}

void Player::drawCard() {
    if (!hand->isFull() && !deck->isEmpty()) {
        unique_ptr<Card> card = deck->draw();
        if (card) {
            hand->addCard(move(card));
        }
    }
}

void Player::discardCard(int index) {
    hand->removeCard(index);
}

void Player::playCard(int index, int targetPlayer, int targetCard) {
    if (index < 0 || index >= hand->getSize()) {
        throw std::out_of_range("Invalid card index");
    }

    Card* card = hand->getCard(index);
    if (magic < card->getCost()) {
        throw std::runtime_error("Not enough magic to play this card");
    }

    if (dynamic_cast<Enchantment*>(card))
    {
        // make sure it has a targetPlayer and targetCard
        if (targetPlayer < 1 || targetPlayer > 2 || targetCard < -1 || targetCard > 4) {
            throw std::invalid_argument("Invalid target player or card index for enchantment");
        }
    }

    if (dynamic_cast<Spell*>(card)) {
        // get the cards command
        unique_ptr<Command> command;
        if (targetPlayer == -1) {
            // no target player, just use the card
            command = card->use();
        } else {
            // use the card with a target player and target card
            command = card->use(targetCard, targetPlayer);
        }

        // notify the game with the command
        game->notify(move(command));
    }

    // incase the spell fails, we only change the magic after the command is executed
    magic -= card->getCost();

    unique_ptr<Card> playedCard = hand->removeCard(index);
    Card* rawCard = playedCard.get();
    if (dynamic_cast<Enchantment*>(rawCard)) {
        unique_ptr<Enchantment> enchantment{static_cast<Enchantment*>(playedCard.release())};
        game->notify(make_unique<ApplyEnchantmentCommand>(targetPlayer, targetCard, move(enchantment)));
        return;
    }
    
    // only add the card to the board if it is a new minion
    if (dynamic_cast<Minion*>(rawCard)) {
        // if the card is a ritual, need to add to ritual slot on board
        board->addCard(move(playedCard));
        trigger(Triggers::MINION_ENTERS_PLAY);
    } else if (dynamic_cast<Ritual*>(rawCard)) {
        board->setRitual(move(playedCard));
    }
}

Minion* Player::getMinion(int index) {
    Card* card = board->getCard(index);
    return dynamic_cast<Minion*>(card);
}

Game* Player::getGame() const {
    return game;
}

Hand* Player::getHand() const {
    return hand.get();
}

Deck* Player::getDeck() const {
    return deck.get();
}

Board* Player::getBoard() const {
    return board.get();
}

Graveyard* Player::getGraveyard() const {
    return graveyard.get();
}

void Player::trigger(Triggers trigger) {
    Ritual* ritual = dynamic_cast<Ritual*>(board->getRitual());

    if (ritual) {
<<<<<<< HEAD
        if (ritual->getNumberOfCharges() - ritual->getActivationCost() >= 0) {
            TriggeredAbility* ability = ritual->getTriggeredAbility();
            if (ability->getTrigger() == trigger) {
                ritual->setNumberOfCharges(ritual->getNumberOfCharges() - ritual->getActivationCost());
=======
        if (ritual->getTriggeredAbility()) {
            TriggeredAbility* ability = ritual->getTriggeredAbility();
            if (ability->getTrigger() == trigger) {
>>>>>>> 3d1e4b3 (dark ritual implementation)
                unique_ptr<Command> command = ability->use();
                game->notify(move(command));
            }
        }
    }
}

int Player::getMagic() const {
    return magic;
}

void Player::setMagic(int magic) {
    this->magic = magic;
}

string Player::getName() const {
    return name;
}

int Player::getHealth() const {
    return health;
}

void Player::setHealth(int health) {
    this->health = health;
}

void Player::killMinion(int index) {
    if (index < 0 || index >= board->getSize()) {
        throw std::out_of_range("Invalid minion index");
    }
    
    auto card = board->removeCard(index);
    if (card) {
        graveyard->addCard(move(card));
    }
    trigger(Triggers::MINION_LEAVES_PLAY);
}

void Player::returnMinionToHand(int index) {
    if (index < 0 || index >= board->getSize()) {
        throw std::out_of_range("Invalid minion index");
    }
    
    auto card = board->removeCard(index);
    if (card) {
        hand->addCard(move(card));
    }
    trigger(Triggers::MINION_LEAVES_PLAY);
}
