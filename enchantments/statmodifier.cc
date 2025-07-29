#include "statmodifier.h"

StatModifier::StatModifier(Player* owner, unique_ptr<Minion> next, int attackModifier, int defenseModifier)
    : Enchantment("Stat Modifier", owner, "", 0, "", "", std::move(next), false), attackModifier(attackModifier), defenseModifier(defenseModifier) {}

int StatModifier::getAttack() const {
    return next->getAttack() + attackModifier;
}

int StatModifier::getDefense() const {
    return next->getDefense() + defenseModifier;
}