#include "allgainstatstrigger.h"
#include "allgainstatscommand.h"

AllGainStatsTrigger::AllGainStatsTrigger(string description, Triggers trigger, int attack, int defense) : 
    TriggeredAbility(description, trigger), attack(attack), defense(defense) {}

unique_ptr<Command> AllGainStatsTrigger::use() {
    return make_unique<AllGainStatsCommand>(attack, defense);
}