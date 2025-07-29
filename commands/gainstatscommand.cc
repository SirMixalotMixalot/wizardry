#include "gainstatscommand.h"
#include "game.h"
#include "minion.h"
#include "statmodifier.h"

GainStatsCommand::GainStatsCommand(int attack, int defense, int index, Player* owner) :
    attack(attack), defense(defense), index(index), owner(owner) {}

void GainStatsCommand::execute(Game& game) {
    Player* activePlayer = game.getActivePlayer();
    Player* inactivePlayer = game.getInactivePlayer();

    if (index == -1) {
        if (game.getActivePlayer() == owner) {
            // game.getLastPlayedMinion()->setAttack(game.getLastPlayedMinion()->getAttack() + attack);
            // game.getLastPlayedMinion()->setDefense(game.getLastPlayedMinion()->getDefense() + defense);
            unique_ptr<StatModifier> modifier = make_unique<StatModifier>(activePlayer, nullptr, attack, defense);
            for (int i = 0; i < activePlayer->getBoard()->getSize(); i++) { // search active player's board for last played minion's index
                if (activePlayer->getMinion(i) == game.getLastPlayedMinion()) {
                    game.applyEnchantment(move(modifier), game.getPlayerNumber(activePlayer), i);
                    break;
                }
            }
        } else {
            Ritual* ritual = dynamic_cast<Ritual*>(owner->getBoard()->getRitual());
            if (ritual) {
                ritual->setNumberOfCharges(ritual->getNumberOfCharges() + ritual->getActivationCost());
            }
        }
    } else {
        if (game.getActivePlayer() == owner) {
            if (activePlayer->getMinion(index)) {
                // activePlayer->getMinion(index)->setAttack(activePlayer->getMinion(index)->getAttack() + attack);
                // activePlayer->getMinion(index)->setDefense(activePlayer->getMinion(index)->getDefense() + defense);
                unique_ptr<StatModifier> modifier = make_unique<StatModifier>(activePlayer, nullptr, attack, defense);
                game.applyEnchantment(move(modifier), game.getPlayerNumber(activePlayer), index);
            }
        } else {
            if (inactivePlayer->getMinion(index)) {
                // inactivePlayer->getMinion(index)->setAttack(inactivePlayer->getMinion(index)->getAttack() + attack);
                // inactivePlayer->getMinion(index)->setDefense(inactivePlayer->getMinion(index)->getDefense() + defense);
                unique_ptr<StatModifier> modifier = make_unique<StatModifier>(inactivePlayer, nullptr, attack, defense);
                game.applyEnchantment(move(modifier), game.getPlayerNumber(inactivePlayer), index);
            }
        }
    }
}
