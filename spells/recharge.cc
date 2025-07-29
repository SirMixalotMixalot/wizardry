#include "recharge.h"

Recharge::Recharge(Player* owner)
        : Spell("Recharge", owner, "Your ritual gains 3 charges", 1) {}

unique_ptr<Command> Recharge::use(int player, int targetCard) {
    throw runtime_error("Recharge spell has no targets.");
}

unique_ptr<Command> Recharge::use() {
    return make_unique<RechargeCommand>();
}
