#include "unsummoncommand.h"
#include "game.h"

UnsummonCommand::UnsummonCommand(int i, bool player1) : index(i), unsummonPlayer1(player1) {}

void UnsummonCommand::execute(Game& game) {
    Player* targetPlayer = unsummonPlayer1 ? game.getPlayer(1) : game.getPlayer(2);
    
    if (index < 0 || index >= targetPlayer->getBoard()->getSize()) {
        throw std::out_of_range("Invalid index for unsummoning a minion.");
    }

    // get the minion to be unsummoned
    Minion* minion = targetPlayer->getMinion(index);
    if (!minion) {
        throw std::runtime_error("No minion found at the specified index.");
    }

    // move the minion to the player's hand
    targetPlayer->returnMinionToHand(index);
}
