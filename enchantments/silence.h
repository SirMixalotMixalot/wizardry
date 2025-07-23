#ifndef SILENCE_H
#define SILENCE_H

#include "../enchantment.h"

class Silence : public Enchantment {
    public:
        Silence(Player* owner, Minion* next);
        ~Silence() override = default;

        bool canUseAbilities() const override; // Return false
};

#endif