#include "allgainstatscommand.h"
#include "game.h"
#include "minion.h"

AllGainStatsCommand::AllGainStatsCommand(int attack, int defense) : attack(attack), defense(defense) {}

void AllGainStatsCommand::execute(Game& game) {
    Player* activePlayer = game.getActivePlayer();
    
    for (int i = 0; i < activePlayer->getBoard()->getSize(); i++) {
        activePlayer->getMinion(i)->setAttack(activePlayer->getMinion(i)->getAttack() + attack);
        activePlayer->getMinion(i)->setDefense(activePlayer->getMinion(i)->getDefense() + defense);
    }
}