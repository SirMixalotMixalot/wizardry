#include "silence.h"

Silence::Silence(Player* owner, unique_ptr<Minion> next) : Enchantment("Silence", owner, "Enchanted minion cannot use abilities", 1, "", "", move(next)) {}

bool Silence::canUseAbilities() const {
    return false;
}
