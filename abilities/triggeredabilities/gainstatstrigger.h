#ifndef GAINSTATSTRIGGER_H
#define GAINSTATSTRIGGER_H

#include "triggeredability.h"

class GainStatsTrigger : public TriggeredAbility {
    int attack;
    int defense;
    int index;
    Player* owner;

    public:
        GainStatsTrigger(string description, Triggers trigger, int attack, int defense, int index, Player* owner);
        ~GainStatsTrigger() override = default;

        virtual unique_ptr<Command> use() override;
};

#endif