#include "banishcommand.h"
#include "game.h"
BanishCommand::BanishCommand(int i, bool player1) : index(i), banishPlayer1(player1) {}

void BanishCommand::execute(Game& game) {
    Player* targetPlayer = banishPlayer1 ? game.getPlayer(1) : game.getPlayer(2);
    
    if (index < 0 || index >= targetPlayer->getBoard()->getSize()) {
        throw std::out_of_range("Invalid index for banishing a minion.");
    }

    // Get the minion to be banished
    Minion* minion = targetPlayer->getMinion(index);
    if (!minion) {
        throw std::runtime_error("No minion found at the specified index.");
    }

    targetPlayer->killMinion(index);
}
