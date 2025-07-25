#include "enrage.h"
using namespace std;

Enrage::Enrage(Player* owner, unique_ptr<Minion> next) : Enchantment("Enrage", owner, "", 2, "*2", "*2", std::move(next)) {}

int Enrage::getAttack() const {
    return next->getAttack() * 2;
}

int Enrage::getDefense() const {
    return next->getDefense() * 2;
}
