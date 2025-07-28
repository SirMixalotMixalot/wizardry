#include "miniongainstatstrigger.h"
#include "gainstatscommand.h"
#include "minion.h"
#include "player.h"

MinionGainStatsTrigger::MinionGainStatsTrigger(string description, Triggers trigger, Minion* minion, int attack, int defense) : 
    TriggeredAbility(description, trigger), minion(minion), attack(attack), defense(defense) {}

unique_ptr<Command> MinionGainStatsTrigger::use() {
    for (int i = 0; i < minion->getOwner()->getBoard()->getSize(); i++) {
        if (minion->getOwner()->getMinion(i) == minion) {
            return make_unique<GainStatsCommand>(attack, defense, i, minion->getOwner());
        }
    }
    return nullptr;
}