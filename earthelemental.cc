#include "earthelemental.h"

using namespace std;

EarthElemental::EarthElemental(Player* owner) : Minion("Earth Elemental", owner, "", 3, 4, 4) {}

bool EarthElemental::canUseAbilities() const {
    return false;
}
