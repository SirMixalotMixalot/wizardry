#include "haste.h"

Haste::Haste(Player* owner, Minion* next) : Enchantment("Haste", owner, "Enchanted minion gains +1 action each turn", 1, "", "", next) {}

int Haste::getActions() const {
    return next->getActions() + 1;
}