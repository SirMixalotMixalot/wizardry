#include "allgainstatscommand.h"
#include "game.h"
#include "minion.h"
#include "statmodifier.h"

AllGainStatsCommand::AllGainStatsCommand(int attack, int defense) : attack(attack), defense(defense) {}

void AllGainStatsCommand::execute(Game& game) {
    Player* activePlayer = game.getActivePlayer();
    
    for (int i = 0; i < activePlayer->getBoard()->getSize(); i++) {
        // activePlayer->getMinion(i)->setAttack(activePlayer->getMinion(i)->getAttack() + attack);
        // activePlayer->getMinion(i)->setDefense(activePlayer->getMinion(i)->getDefense() + defense);

        // Create a unique pointer for a StatModifier Enhantment
        unique_ptr<StatModifier> modifier = make_unique<StatModifier>(activePlayer, nullptr, attack, defense);
        int playerNumber = game.getPlayerNumber(activePlayer);
        game.applyEnchantment(move(modifier), playerNumber, i); // Apply the enchantment to the minion
    }
}