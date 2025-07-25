#include "haste.h"

Haste::Haste(Player* owner, unique_ptr<Minion> next) : Enchantment("Haste", owner, "Enchanted minion gains +1 action each turn", 1, "", "", move(next)) {}

void Haste::restoreActions() {
    next->restoreActions();
    setActions(getActions() + 1);
}

void Haste::setNext(unique_ptr<Minion> nextMinion) {
    next = std::move(nextMinion);
    // immediately apply the haste effect
    next->setActions(next->getActions() + 1);
}


