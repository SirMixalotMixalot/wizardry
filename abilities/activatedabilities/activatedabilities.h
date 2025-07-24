#ifndef ACTIVATEDABILITIES_H
#define ACTIVATEDABILITIES_H

#include "../abilities.h"

class ActivatedAbility : public Ability {
    int cost;

    public:
        ActivatedAbility(string description, int cost);
        ~ActivatedAbility() override = default;

        unique_ptr<Command> use() = 0;
        unique_ptr<Command> use(int player, int targetCard) = 0;

        int getCost() const;
};

#endif