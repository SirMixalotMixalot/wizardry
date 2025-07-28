#ifndef GAINMAGICTRIGGER_H
#define GAINMAGICTRIGGER_H

#include "triggeredability.h"

class GainMagicTrigger : public TriggeredAbility {
    int magic;

    public:
        GainMagicTrigger(string description, Triggers trigger, int magic);
        ~GainMagicTrigger() override = default;

        virtual unique_ptr<Command> use() override;
};

#endif