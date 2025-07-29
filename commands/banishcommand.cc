#include "banishcommand.h"
#include "game.h"
BanishCommand::BanishCommand(int t, bool player1) : targetCard(t), banishPlayer1(player1) {}

void BanishCommand::execute(Game& game) {

    Player* targetPlayer = banishPlayer1 ? game.getPlayer(1) : game.getPlayer(2);

    if (targetCard == -1)
    {
        // destroy ritual
        targetPlayer->getBoard()->setRitual(nullptr);
    }
    else 
    {
        // destroy minion
        targetPlayer->getBoard()->destroyCard(targetCard);
    }




    
}
