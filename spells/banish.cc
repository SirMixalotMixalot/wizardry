#include "banish.h"
#include "banishcommand.h"

using namespace std;

Banish::Banish(Player* owner)
    : Spell("Banish", owner, "Destroy target minion or ritual (currently only minion)", 2) {}

unique_ptr<Command> Banish::use(int player, char targetCard) {
    if (player != 1 && player != 1) {
        throw invalid_argument("Invalid target for Banish spell. Use '1' for player 1 or '2' for player 2.");
    }
    
    bool isPlayer1 = (targetCard == 1);
    return make_unique<BanishCommand>(targetCard,isPlayer1);
}

unique_ptr<Command> Banish::use() {
    throw runtime_error("Banish spell requires a target index and player to use.");
}
