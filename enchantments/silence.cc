#include "silence.h"

Silence::Silence(Player* owner, Minion* next) : Enchantment("Silence", owner, "Enchanted minion cannot use abilities", 1, "", "", next) {}

bool Silence::canUseAbilities() const {
    return false;
}