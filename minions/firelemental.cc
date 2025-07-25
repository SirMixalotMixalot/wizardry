#include "firelemental.h"

using namespace std;

FireElemental::FireElemental(Player* owner) 
    : Minion("Fire Elemental", owner, "", 2, 2, 3, nullptr) {}

bool FireElemental::canUseAbilities() const {
    return true;
}
