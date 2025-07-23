#include "giantstrength.h"

GiantStrength::GiantStrength(Player* owner, unique_ptr<Minion> next) : Enchantment("Giant Strength", owner, "", 1, "+2", "+2", move(next)) {}

int GiantStrength::getAttack() const {
    return next->getAttack() + 2;
}

int GiantStrength::getDefense() const {
    return next->getDefense() + 2;
}
