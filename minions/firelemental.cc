#include "firelemental.h"
#include "damagetrigger.h"

using namespace std;

FireElemental::FireElemental(Player* owner) 
    : Minion("Fire Elemental", owner, "", 2, 2, 3, nullptr,
    make_unique<DamageTrigger>("Whenever an opponent's minion enters play, deal 1 damage to it.", Triggers::MINION_ENTERS_PLAY, owner, 1)) {}

bool FireElemental::canUseAbilities() const {
    return true;
}
