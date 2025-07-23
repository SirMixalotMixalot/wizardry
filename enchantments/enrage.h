#ifndef ENRAGE_H
#define ENRAGE_H

#include "../enchantment.h"

class Enrage : public Enchantment {
    public:
        Enrage(Player* owner, Minion* next);
        ~Enrage() override = default;

        int getAttack() const override; // Multiply 2 to next's attack
        int getDefense() const override; // Multiply 2 to next's defense
};

#endif