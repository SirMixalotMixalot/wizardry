#ifndef SUMMONMINIONS_H
#define SUMMONMINIONS_H

#include "activatedability.h"

class SummonMinions : public ActivatedAbility {
    string minionName;
    int minionCount;
    public:
        SummonMinions(string description, int cost, string minionName, int minionCount);
        ~SummonMinions() override = 0;

        unique_ptr<Command> use() override;
        unique_ptr<Command> use(int player, int targetCard) override;
};

#endif