#ifndef MAGIC_FATIGUE_H
#define MAGIC_FATIGUE_H

#include "enchantment.h"

class MagicFatigue : public Enchantment {
    public:
        MagicFatigue(Player* owner, unique_ptr<Minion> next);
        ~MagicFatigue() override = default;

        int getActivatedAbilityCost() const override; // Add 2 to next's activated ability cost
};

#endif
