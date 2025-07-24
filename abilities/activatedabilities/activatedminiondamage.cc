#include "activatedminiondamage.h"
#include "damageminioncommand.h"

ActivatedMinionDamage::ActivatedMinionDamage() : ActivatedAbility("Deal 1 damage to target minion", 1) {}

unique_ptr<Command> ActivatedMinionDamage::use() {
    throw runtime_error("This activated ability requires a target index and player to use.");
}

unique_ptr<Command> ActivatedMinionDamage::use(int player, int targetCard) {
    bool isPlayer1 = (player == 1);
    return make_unique<DamageMinionCommand>(targetCard, isPlayer1);
}