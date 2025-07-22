#include "airelemental.h"
#include <iostream>

using namespace std;

AirElemental::AirElemental(Player* owner) : Minion("Air Elemental", owner, "", 0, 1, 1) {
}

bool AirElemental::canUseAbilities() const {
    return false;
}