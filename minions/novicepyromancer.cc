#include "novicepyromancer.h"

using namespace std;

NovicePyromancer::NovicePyromancer(Player* owner) 
    : Minion("Novice Pyromancer", owner, "", 1, 0, 1) {}

bool NovicePyromancer::canUseAbilities() const {
    return true;
}
