#include "miniongainstatstrigger.h"
#include "gainstatscommand.h"
#include "minion.h"
#include "player.h"
#include "enchantment.h"
#include <iostream>
using namespace std;

MinionGainStatsTrigger::MinionGainStatsTrigger(string description, Triggers trigger, Minion* minion, int attack, int defense) : 
    TriggeredAbility(description, trigger), minion(minion), attack(attack), defense(defense) {}

unique_ptr<Command> MinionGainStatsTrigger::use() {
    for (int i = 0; i < minion->getOwner()->getBoard()->getSize(); i++) {
        const Minion* currentMinion = minion->getOwner()->getMinion(i);
        // get to base minion
        while (auto enchantment = dynamic_cast<const Enchantment*>(currentMinion)) {
            currentMinion = enchantment->getNext();
        }
        if (currentMinion == minion) {
            return make_unique<GainStatsCommand>(attack, defense, i, minion->getOwner());
        }
    }
    return nullptr;
}