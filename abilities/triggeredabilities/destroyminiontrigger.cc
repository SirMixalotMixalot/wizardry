#include "destroyminiontrigger.h"
#include "destroyminioncommand.h"

DestroyMinionTrigger::DestroyMinionTrigger(string description, Triggers trigger, Player* owner) : TriggeredAbility(description, trigger), owner(owner) {}

unique_ptr<Command> DestroyMinionTrigger::use() {
    return make_unique<DestroyMinionCommand>(owner);
}