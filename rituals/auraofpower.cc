#include "auraofpower.h"
#include "gainstatstrigger.h"
#include "player.h"

AuraOfPower::AuraOfPower(Player* owner) : Ritual("Aura of Power", owner, "Whenever a minion enters play under your control, it gains +1/+1", 1, 
    make_unique<GainStatsTrigger>("Whenever a minion enters play under your control, it gains +1/+1", Triggers::MINION_ENTERS_PLAY, 1, 1, -1, owner), 
    1, 4) {}
