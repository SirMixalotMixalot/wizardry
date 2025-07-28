#include "gainstatstrigger.h"
#include "gainstatscommand.h"

GainStatsTrigger::GainStatsTrigger(string description, Triggers trigger, int attack, int defense, int index, Player* owner) :
    TriggeredAbility(description, trigger), attack(attack), defense(defense), index(index), owner(owner) {}


unique_ptr<Command> GainStatsTrigger::use() {
    return make_unique<GainStatsCommand>(attack, defense, index, owner);
}
