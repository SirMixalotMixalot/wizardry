#include "gainstatscommand.h"
#include "game.h"
#include "minion.h"

GainStatsCommand::GainStatsCommand(int attack, int defense, int index, Player* owner) :
    attack(attack), defense(defense), index(index), owner(owner) {}

void GainStatsCommand::execute(Game& game) {
    Player* activePlayer = game.getActivePlayer();
    Player* inactivePlayer = game.getInactivePlayer();

    if (index == -1) {
        if (game.getActivePlayer() == owner) {
            game.getLastPlayedMinion()->setAttack(game.getLastPlayedMinion()->getAttack() + attack);
            game.getLastPlayedMinion()->setDefense(game.getLastPlayedMinion()->getDefense() + defense);
        } else {
            Ritual* ritual = dynamic_cast<Ritual*>(owner->getBoard()->getRitual());
            if (ritual) {
                ritual->setNumberOfCharges(ritual->getNumberOfCharges() + ritual->getActivationCost());
            }
        }
    } else {
        if (game.getActivePlayer() == owner) {
            if (activePlayer->getMinion(index)) {
                activePlayer->getMinion(index)->setAttack(activePlayer->getMinion(index)->getAttack() + attack);
                activePlayer->getMinion(index)->setDefense(activePlayer->getMinion(index)->getDefense() + defense);
            }
        } else {
            if (inactivePlayer->getMinion(index)) {
                inactivePlayer->getMinion(index)->setAttack(inactivePlayer->getMinion(index)->getAttack() + attack);
                inactivePlayer->getMinion(index)->setDefense(inactivePlayer->getMinion(index)->getDefense() + defense);
            }
        }
    }
}
