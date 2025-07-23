#ifndef ENCHANTMENT_H
#define ENCHANTMENT_H

#include "minion.h"

class Enchantment : public Minion {
    string attackModifier;
    string defenseModifier;

    protected:
        Minion* next;
    public:
        Enchantment(string name, Player* owner, string description, int cost, string attackModifier, string defenseModifier, Minion* next);
        ~Enchantment() override = default;

        string getAttackModifier() const;
        string getDefenseModifier() const;

        void use() override; // call next's use()
        void use(int index, char target) override; // call next's use(int, char)

        void restoreActions() override; // call next's restoreActions()

        int getAttack() const override;
        int getDefense() const override;
        int getActions() const override;
        bool canUseAbilities() const = 0;

        void setAttack(int attack) override; // call next's setAttack()
        void setDefense(int defense) override; // call next's setDefense()
        void setActions(int actions) override; // call next's setActions()
};

#endif