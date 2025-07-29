#ifndef STATMODIFIER_H
#define STATMODIFIER_H

#include "enchantment.h"

class StatModifier : public Enchantment {
    int attackModifier;
    int defenseModifier;

    public:
        StatModifier(Player* owner, unique_ptr<Minion> next, int attackModifier, int defenseModifier);
        ~StatModifier() override = default;

        int getAttack() const override;
        int getDefense() const override;
};

#endif