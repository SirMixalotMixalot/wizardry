#include "damageminion.h"
#include "damageminioncommand.h"

DamageMinion::DamageMinion(string description, int cost, int damage) : ActivatedAbility(move(description), cost), damage(damage) {}

DamageMinion::~DamageMinion() = default;

unique_ptr<Command> DamageMinion::use() {
    throw runtime_error("This activated ability requires a target index and player to use.");
}

unique_ptr<Command> DamageMinion::use(int player, int targetCard) {
    bool isPlayer1 = (player == 1);
    return make_unique<DamageMinionCommand>(targetCard, isPlayer1, damage);
}