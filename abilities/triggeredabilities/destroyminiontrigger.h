#ifndef DESTROYMINIONTRIGGER_H
#define DESTROYMINIONTRIGGER_H

#include "triggeredability.h"

class DestroyMinionTrigger : public TriggeredAbility {
    Player* owner;

    public:
        DestroyMinionTrigger(string description, Triggers trigger, Player* owner);
        ~DestroyMinionTrigger() override = default;

        virtual unique_ptr<Command> use() override;
};

#endif
