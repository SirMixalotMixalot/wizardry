#include "rechargecommand.h"
#include "game.h"

using namespace std;

void RechargeCommand::execute(Game& game) {
    Player* activePlayer = game.getActivePlayer();
    
    // Check if the player has a ritual on the board
    Card* r = activePlayer->getBoard()->getRitual();
    Ritual* ritual = dynamic_cast<Ritual*>(r);
    if (ritual == nullptr) {
        throw runtime_error("No ritual on the board to recharge.");
    }

    ritual->setNumberOfCharges(ritual->getNumberOfCharges() + 3);
    
}
