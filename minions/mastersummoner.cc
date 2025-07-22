#include "mastersummoner.h"

using namespace std;

MasterSummoner::MasterSummoner(Player* owner) 
    : Minion("Master Summoner", owner, "", 3, 2, 3) {}

bool MasterSummoner::canUseAbilities() const {
    return true;
}
