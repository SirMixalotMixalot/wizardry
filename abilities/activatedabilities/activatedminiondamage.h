#ifndef ACTIVATEDMINIONDAMAGE_H
#define ACTIVATEDMINIONDAMAGE_H

#include "activatedability.h"

class ActivatedMinionDamage : public ActivatedAbility {
    public:
        ActivatedMinionDamage();
        ~ActivatedMinionDamage() override = default;
        
        unique_ptr<Command> use() override;
        unique_ptr<Command> use(int player, int targetCard) override;
};

#endif