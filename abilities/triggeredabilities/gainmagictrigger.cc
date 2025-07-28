#include "gainmagictrigger.h"
#include "gainmagiccommand.h"

using namespace std;

GainMagicTrigger::GainMagicTrigger(string description, Triggers trigger, int magic) 
    : TriggeredAbility(description, trigger), magic(magic) {}

unique_ptr<Command> GainMagicTrigger::use() {
    return make_unique<GainMagicCommand>(magic);
}
