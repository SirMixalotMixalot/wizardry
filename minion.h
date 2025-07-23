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

        int getAttack() const;
        int getDefense() const;
        int getActions() const;
        virtual bool canUseAbilities() const = 0;

        unique_ptr<Command> use() override; // activated ability
        unique_ptr<Command> use(int index, int target) override;

        void restoreActions();

        void setAttack(int attack);
        void setDefense(int defense);
        void setActions(int actions);
};

#endif
