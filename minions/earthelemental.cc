#include "earthelemental.h"
#include <iostream>

using namespace std;

EarthElemental::EarthElemental(Player* owner) : Minion("Earth Elemental", owner, "", 3, 4, 4, nullptr) {
}

bool EarthElemental::canUseAbilities() const {
    return false;
}
