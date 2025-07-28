#ifndef MINIONGAINSTATSTRIGGER_H
#define MINIONGAINSTATSTRIGGER_H

#include "triggeredability.h"

class MinionGainStatsTrigger : public TriggeredAbility {
    Minion* minion;
    int attack;
    int defense;

    public:
        MinionGainStatsTrigger(string description, Triggers trigger, Minion* minion, int attack, int defense);
        ~MinionGainStatsTrigger() override = default;

        virtual unique_ptr<Command> use() override;
};

#endif