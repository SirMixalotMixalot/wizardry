#ifndef RECHARGE_H
#define RECHARGE_H
#include "spell.h"

#include "rechargecommand.h"

class Recharge : public Spell {
public:
    Recharge(Player* owner)
        : Spell("Recharge", owner, "Recharge your ritual by 3 charges", 1) {}

    unique_ptr<Command> use(int player, int targetCard) override {
        throw runtime_error("Recharge spell has no targets.");
    }

    unique_ptr<Command> use() override {
        return make_unique<RechargeCommand>();
    }
};

#endif
