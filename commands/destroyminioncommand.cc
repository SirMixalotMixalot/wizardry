#include "destroyminioncommand.h"
#include "game.h"

DestroyMinionCommand::DestroyMinionCommand(Player* owner) : owner(owner) {}

void DestroyMinionCommand::execute(Game& game) {
    Player* activePlayer = game.getActivePlayer();
    Minion* target = game.getLastPlayedMinion();

    if (target) {
        activePlayer->getBoard()->removeCard(activePlayer->getBoard()->getSize() - 1);
        game.setLastPlayedMinion(nullptr);
    } else {
        Ritual* ritual = dynamic_cast<Ritual*>(owner->getBoard()->getRitual());
        if (ritual) {
            ritual->setNumberOfCharges(ritual->getNumberOfCharges() + ritual->getActivationCost());
        }
    }
}
