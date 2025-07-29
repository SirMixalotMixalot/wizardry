#ifndef STATSETTER_H
#define STATSETTER_H

#include "enchantment.h"

class StatSetter : public Enchantment {
    int attack;
    int defense;

    public:
        StatSetter(Player* owner, unique_ptr<Minion> next, int attack, int defense);
        ~StatSetter() override = default;

        int getAttack() const override;
        int getDefense() const override;
};

#endif