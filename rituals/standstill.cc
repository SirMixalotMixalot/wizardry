#include "standstill.h"
#include "destroyminiontrigger.h"

Standstill::Standstill(Player* owner) : Ritual("Standstill", owner, "Whenever a minion enters play, destroy it", 3,
    make_unique<DestroyMinionTrigger>("Whenever a minion enters play, destroy it", Triggers::MINION_ENTERS_PLAY, owner),
    2,4) {}
