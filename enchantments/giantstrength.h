#ifndef GIANT_STRENGTH_H
#define GIANT_STRENGTH_H

#include "enchantment.h"

class GiantStrength : public Enchantment {
    public:
        GiantStrength(Player* owner, unique_ptr<Minion> next);
        ~GiantStrength() override = default;

        int getAttack() const override; // Add 2 to next's attack
        int getDefense() const override; // Add 2 to next's defense
};

#endif
