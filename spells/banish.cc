#include "banish.h"
#include "banishcommand.h"

using namespace std;

Banish::Banish(Player* owner)
    : Spell("Banish", owner, "Destroy target minion or ritual (currently only minion)", 2) {}

unique_ptr<Command> Banish::use(int player, int targetCard) {    
    bool isPlayer1 = (player == 1);
    return make_unique<BanishCommand>(targetCard,isPlayer1);
}

unique_ptr<Command> Banish::use() {
    throw runtime_error("Banish spell requires a target index and player to use.");
}
