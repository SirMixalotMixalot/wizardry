#include "magicfatigue.h"

MagicFatigue::MagicFatigue(Player* owner, Minion* next) : Enchantment("Magic Fatigue", owner, "Enchanted minion's activated ability costs 2 more", 0, "", "", next) {}

int MagicFatigue::getActivatedAbilityCost() const {
    return next->getActivatedAbilityCost() + 2;
}