#include "magicfatigue.h"

MagicFatigue::MagicFatigue(Player* owner, unique_ptr<Minion> next) : Enchantment("Magic Fatigue", owner, "Enchanted minion's activated ability costs 2 more", 0, "", "", move(next)) {}

int MagicFatigue::getActivatedAbilityCost() const {
    return next->getActivatedAbilityCost() + 2;
}
