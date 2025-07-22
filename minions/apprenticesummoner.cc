#include "apprenticesummoner.h"

using namespace std;

ApprenticeSummoner::ApprenticeSummoner(Player* owner) 
    : Minion("Apprentice Summoner", owner, "", 1, 1, 1) {}
bool ApprenticeSummoner::canUseAbilities() const {
    return true;
}
