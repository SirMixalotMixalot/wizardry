#ifndef DAMAGEMINION_H
#define DAMAGEMINION_H

#include "activatedability.h"

class DamageMinion : public ActivatedAbility {
    int damage;
    public:
        DamageMinion(string description, int cost, int damage);
        ~DamageMinion() override = 0;
        
        unique_ptr<Command> use() override;
        unique_ptr<Command> use(int player, int targetCard) override;
};

#endif