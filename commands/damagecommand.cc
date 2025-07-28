#include "damagecommand.h"
#include "game.h"
#include "player.h"
#include "minion.h"

DamageCommand::DamageCommand(Player* owner, int damage) : owner(owner), damage(damage) {}

void DamageCommand::execute(Game& game) {
    Player* activePlayer = game.getActivePlayer();
    Player* inactivePlayer = game.getInactivePlayer();

    if (owner == inactivePlayer) {
        if (activePlayer->getBoard()->getSize() > 0) {
            int index = activePlayer->getBoard()->getSize() - 1;
            activePlayer->getMinion(index)->setDefense(activePlayer->getMinion(index)->getDefense() - damage);
            if (activePlayer->getMinion(index)->getDefense() <= 0) {
                if (activePlayer->getMinion(index) == game.getLastPlayedMinion()) {
                    game.setLastPlayedMinion(nullptr);
                }
                activePlayer->killMinion(index);
            }
        }
    }  
}