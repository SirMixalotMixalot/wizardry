#ifndef ALLGAINSTATSTRIGGER_H
#define ALLGAINSTATSTRIGGER_H

#include "triggeredability.h"

class AllGainStatsTrigger : public TriggeredAbility {
    int attack;
    int defense;

    public:
        AllGainStatsTrigger(string description, Triggers trigger, int attack, int defense);
        ~AllGainStatsTrigger() override = default;

        virtual unique_ptr<Command> use() override;
};

#endif