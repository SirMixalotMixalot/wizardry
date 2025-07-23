#ifndef MINION_H
#define MINION_H

#include "card.h"

class Minion : public Card {
    int attack;
    int defense;
    int actions;

    public:
        Minion(string name, Player* owner, string description, int cost, int attack, int defense);
        ~Minion() override = default;

        virtual int getAttack() const;
        virtual int getDefense() const;
        virtual int getActions() const;
        virtual bool canUseAbilities() const = 0;

        void use() override; // activated ability
        void use(int index, char target) override;

        virtual void restoreActions();

        virtual void setAttack(int attack);
        virtual void setDefense(int defense);
        virtual void setActions(int actions);
};

#endif
