#ifndef HASTE_H
#define HASTE_H

#include "../enchantment.h"

class Haste : public Enchantment {
    public:
        Haste(Player* owner, Minion* next);
        ~Haste() override = default;

        int getActions() const override; // Add 1 to next's actions
};

#endif