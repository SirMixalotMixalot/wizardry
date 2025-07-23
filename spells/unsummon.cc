#include "unsummon.h"
#include "unsummoncommand.h"

using namespace std;

Unsummon::Unsummon(Player* owner)
    : Spell("Unsummon", owner, "Return target minion to its owner's hand", 1) {}

unique_ptr<Command> Unsummon::use(int index, char target) {
    if (target != '1' && target != '2') {
        throw invalid_argument("Invalid target for Unsummon spell. Use '1' for player 1 or '2' for player 2.");
    }
    
    bool isPlayer1 = (target == '1');
    return make_unique<UnsummonCommand>(index, isPlayer1);
}

unique_ptr<Command> Unsummon::use() {
    throw runtime_error("Unsummon spell requires a target index and player to use.");
}
