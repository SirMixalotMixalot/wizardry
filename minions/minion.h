#ifndef MINION_H
#define MINION_H

#include "card.h"
#include "command.h"
#include "activatedability.h"

#include "triggeredability.h"

class Minion : public Card {
    int attack;
    int defense;
    int actions;
    unique_ptr<TriggeredAbility> triggeredAbility;
    unique_ptr<ActivatedAbility> activatedAbility;

    public:
        Minion(string name, Player* owner, string description, int cost, int attack, int defense, unique_ptr<ActivatedAbility> activatedAbility);
        ~Minion() override = default;

        virtual int getAttack() const;
        virtual int getDefense() const;
        virtual int getActions() const;
        TriggeredAbility* getTriggeredAbility() const;
        virtual int getActivatedAbilityCost() const;
        virtual bool canUseAbilities() const = 0;

        unique_ptr<Command> use() override; // activated ability
        unique_ptr<Command> use(int index, int target) override;

        virtual void restoreActions();

        virtual void setAttack(int attack);
        virtual void setDefense(int defense);
        virtual void setActions(int actions);
};

#endif
