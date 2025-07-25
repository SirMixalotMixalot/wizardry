#include "usecommand.h"
#include "game.h"

UseCommand::UseCommand(int cardIndex, int playerIndex, int targetIndex)
    : cardIndex(cardIndex), playerIndex(playerIndex), targetIndex(targetIndex) {}

void UseCommand::execute(Game& game) {
    if (playerIndex == -1) {
        game.useMinion(cardIndex);
    } else {
        game.useMinion(cardIndex, playerIndex, targetIndex);
    }
}
