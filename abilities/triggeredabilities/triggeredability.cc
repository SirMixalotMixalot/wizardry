#include "triggeredability.h"

using namespace std;

TriggeredAbility::TriggeredAbility(string description, Triggers trigger)
    : Ability(description), trigger(trigger) {}

TriggeredAbility::~TriggeredAbility() = default;

Triggers TriggeredAbility::getTrigger() {
    return trigger;
}
