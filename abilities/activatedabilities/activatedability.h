#ifndef ACTIVATEDABILITY_H
#define ACTIVATEDABILITY_H

#include "ability.h"

class ActivatedAbility : public Ability {
    int cost;

    public:
        ActivatedAbility(string description, int cost);
        ~ActivatedAbility() override = default;

        virtual unique_ptr<Command> use() = 0;
        virtual unique_ptr<Command> use(int player, int targetCard) = 0;

        int getCost() const;
};

#endif