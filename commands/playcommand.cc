#include "playcommand.h"
#include "game.h"

PlayCommand::PlayCommand(int cardIndex, int playerIndex, int targetIndex)
    : cardIndex(cardIndex), playerIndex(playerIndex), targetIndex(targetIndex) {}

void PlayCommand::execute(Game& game) {
    if (playerIndex == -1) {
        game.playCard(cardIndex);
    } else {
        game.playCard(cardIndex, playerIndex, targetIndex);
    }
}
