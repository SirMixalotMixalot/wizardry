#ifndef RECHARGE_H
#define RECHARGE_H
#include "spell.h"

#include "rechargecommand.h"

class Recharge : public Spell {
public:
    Recharge(Player* owner);
    unique_ptr<Command> use(int player, int targetCard) override;
    unique_ptr<Command> use() override;
};

#endif
