#include "apprenticesummoner.h"
#include "apprenticesummonerability.h"

using namespace std;

ApprenticeSummoner::ApprenticeSummoner(Player* owner) 
    : Minion("Apprentice Summoner", owner, "", 1, 1, 1, make_unique<ApprenticeSummonerAbility>()) {}

bool ApprenticeSummoner::canUseAbilities() const {
    return true;
}
