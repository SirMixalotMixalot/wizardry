#include "blizzard.h"
#include "blizzardcommand.h"

Blizzard::Blizzard(Player* owner)
    : Spell("Blizzard", owner, "Deal 2 damage to all minions", 3) {}

unique_ptr<Command> Blizzard::use() {
    return make_unique<BlizzardCommand>();
}

unique_ptr<Command> Blizzard::use(int index, char target) {
    throw runtime_error("Blizzard spell does not require a target index or player.");
}
