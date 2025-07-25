#include "novicepyromancer.h"
#include "novicepyromancerability.h"

using namespace std;

NovicePyromancer::NovicePyromancer(Player* owner)
    : Minion("Novice Pyromancer", owner, "", 1, 0, 1, make_unique<NovicePyromancerAbility>()) {
}

bool NovicePyromancer::canUseAbilities() const {
    return true;
}
