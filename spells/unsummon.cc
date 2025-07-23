#include "unsummon.h"
#include "unsummoncommand.h"

using namespace std;

Unsummon::Unsummon(Player* owner)
    : Spell("Unsummon", owner, "Return target minion to its owner's hand", 1) {}

unique_ptr<Command> Unsummon::use(int player, int targetCard) {
    bool isPlayer1 = (player == '1');

    if (targetCard == -1)
    {
        throw runtime_error("Unsummon spell cannot target a ritual. Please target a minion.");
    }
    return make_unique<UnsummonCommand>(targetCard, isPlayer1);
}

unique_ptr<Command> Unsummon::use() {
    throw runtime_error("Unsummon spell requires a target index and player to use.");
}
