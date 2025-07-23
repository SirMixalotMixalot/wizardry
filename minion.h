#ifndef MINION_H
#define MINION_H

#include "card.h"
#include "command.h"
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
        virtual int getActivatedAbilityCost() const; // NOTE: IMPLEMENTATION NEEDED
        virtual bool canUseAbilities() const = 0;

        unique_ptr<Command> use() override; // activated ability
        unique_ptr<Command> use(int index, int target) override;

        virtual void restoreActions();

        virtual void setAttack(int attack);
        virtual void setDefense(int defense);
        virtual void setActions(int actions);
};

#endif
