#include "mastersummoner.h"
#include "mastersummonerability.h"

using namespace std;

MasterSummoner::MasterSummoner(Player* owner) 
    : Minion("Master Summoner", owner, "", 3, 2, 3, make_unique<MasterSummonerAbility>()) {}

bool MasterSummoner::canUseAbilities() const {
    return true;
}
