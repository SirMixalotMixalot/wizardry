#include "attackcommand.h"
#include "game.h"

AttackCommand::AttackCommand(int attackerIndex, int targetIndex) 
    : attackerIndex(attackerIndex), targetIndex(targetIndex) {}

void AttackCommand::execute(Game& game) {
    if (targetIndex == -1) {
        game.attack(attackerIndex);
    } else {
        game.attack(attackerIndex, targetIndex);
    }
}
