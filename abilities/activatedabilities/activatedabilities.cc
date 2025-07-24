#include "activatedabilities.h"

ActivatedAbility::ActivatedAbility(string description, int cost) : Ability(move(description)), cost(cost) {}

int ActivatedAbility::getCost() const {
    return cost;
}