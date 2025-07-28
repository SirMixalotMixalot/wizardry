#include "disenchantment.h"
#include "disenchantmentcommand.h"
Disenchantment::Disenchantment(Player* owner) : Spell("Disenchant", owner, "Destroy the top enchantment on target minion", 1)
{}

unique_ptr<Command> Disenchantment::use()
{
    throw new runtime_error("Disenchantment requires a target minion");
}

unique_ptr<Command> Disenchantment::use(int targetPlayer, int targetCard)
{
    return make_unique<DisenchantmentCommand>(targetPlayer, targetCard);
}
