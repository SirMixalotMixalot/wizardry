#include "giantstrength.h"

GiantStrength::GiantStrength(Player* owner, Minion* next) : Enchantment("Giant Strength", owner, "", 1, "+2", "+2", next) {}

int GiantStrength::getAttack() const {
    return next->getAttack() + 2;
}

int GiantStrength::getDefense() const {
    return next->getDefense() + 2;
}