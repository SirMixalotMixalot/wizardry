#ifndef DAMAGETRIGGER_H
#define DAMAGETRIGGER_H

#include "triggeredability.h"

class DamageTrigger : public TriggeredAbility {
    Player* owner;
    int damage;

    public:
        DamageTrigger(string description, Triggers trigger, Player* owner, int damage);
        ~DamageTrigger() override = default;

        virtual unique_ptr<Command> use() override;
};

#endif
