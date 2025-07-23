#include "enrage.h"

Enrage::Enrage(Player* owner, Minion* next) : Enchantment("Enrage", owner, "", 2, "*2", "*2", next) {}

int Enrage::getAttack() const {
    return next->getAttack() * 2;
}

int Enrage::getDefense() const {
    return next->getDefense() * 2;
}