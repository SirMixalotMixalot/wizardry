#include "activatedability.h"

using namespace std;

ActivatedAbility::ActivatedAbility(string description, int cost) : Ability(move(description)), cost(cost) {}

int ActivatedAbility::getCost() const {
    return cost;
}