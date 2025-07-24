#include "activatedminiondamage.h"
#include "attackcommand.h"

ActivatedMinionDamage::ActivatedMinionDamage() : ActivatedAbility("Deal 1 damage to target minion", 1) {}

unique_ptr<Command> ActivatedMinionDamage::use() {
    throw runtime_error("This activated ability requires a target index and player to use.");
}

unique_ptr<Command> ActivatedMinionDamage::use(int player, int targetCard) {
    return make_unique<AttackCommand>(player - 1, targetCard - 1); // Assumed that you need to substrct 1 because AttackCommand takes indices. Change implementation later if needed.
}
// NOTE: just realized AttackCommand starts a clash, but we just need to deal 1 damage to the target. Need to make a new command.