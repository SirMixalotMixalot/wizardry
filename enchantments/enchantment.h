#ifndef ENCHANTMENT_H
#define ENCHANTMENT_H

#include "minion.h"
#include "command.h"
#include <memory>
using namespace std;
class Enchantment : public Minion {
    string attackModifier;
    string defenseModifier;
    bool displayable;

    protected:
        unique_ptr<Minion> next;
    public:
        Enchantment(string name, Player* owner, string description, int cost, string attackModifier, string defenseModifier, unique_ptr<Minion> next, bool displayable = true);
        ~Enchantment() override = 0;

        string getAttackModifier() const;
        string getDefenseModifier() const;

        unique_ptr<Command> use() override; // call next's use()
        unique_ptr<Command> use(int index, int target) override; // call next's use(int, char)

        void restoreActions() override; // call next's restoreActions()

        int getAttack() const override;
        int getDefense() const override;
        int getActions() const override;
        TriggeredAbility* getTriggeredAbility() const override;
        ActivatedAbility* getActivatedAbility() const override;
        int getActivatedAbilityCost() const override;
        bool canUseAbilities() const override;

        void setAttack(int attack) override; // call next's setAttack()
        void setDefense(int defense) override; // call next's setDefense()
        void setActions(int actions) override; // call next's setActions()
        std::unique_ptr<Minion>& ownNext();

        virtual void setNext(unique_ptr<Minion> nextMinion);
        const Minion* getNext() const;
        unique_ptr<Minion> releaseNext();
        virtual bool displayableEnchantment() const;
};

#endif
