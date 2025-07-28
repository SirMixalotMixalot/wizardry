#include "darkritual.h"
#include "gainmagictrigger.h"

using namespace std;

DarkRitual::DarkRitual(Player* owner) 
: Ritual("Dark Ritual", owner, "At the start of your turn, gain 1 magic", 0, 
    make_unique<GainMagicTrigger>("At the start of your turn, gain 1 magic", Triggers::START_OF_TURN, 1), 
    1, 5) {}

