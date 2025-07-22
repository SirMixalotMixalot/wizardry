#include "potionseller.h"

using namespace std;

PotionSeller::PotionSeller(Player* owner) 
    : Minion("Potion Seller", owner, "", 2, 1, 3) {}

bool PotionSeller::canUseAbilities() const {
    return true;
}
