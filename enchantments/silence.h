#ifndef SILENCE_H
#define SILENCE_H

#include "enchantment.h"
using namespace std;
class Silence : public Enchantment {
    public:
        Silence(Player* owner, unique_ptr<Minion> next);
        ~Silence() override = default;

        bool canUseAbilities() const override; // Return false
};

#endif
