#include "potionseller.h"
#include "allgainstatstrigger.h"

using namespace std;

PotionSeller::PotionSeller(Player* owner) 
    : Minion("Potion Seller", owner, "", 2, 1, 3, nullptr, 
        make_unique<AllGainStatsTrigger>("At the end of your turn, all your minions gain +0/+1.", Triggers::END_OF_TURN, 0, 1)) {}

bool PotionSeller::canUseAbilities() const {
    return true;
}
