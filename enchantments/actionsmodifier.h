#ifndef ACTIONSMODIFIER_H
#define ACTIONSMODIFIER_H

#include "enchantment.h"

class ActionsModifier : public Enchantment {
    int actionsModifier;

    public:
        ActionsModifier(Player* owner, unique_ptr<Minion> next, int actionsModifier);
        ~ActionsModifier() override = default;

        int getActions() const override;
};

#endif