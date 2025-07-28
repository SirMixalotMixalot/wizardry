#include "disenchantmentcommand.h"
#include "game.h"

DisenchantmentCommand::DisenchantmentCommand(int targetPlayer, int targetCard)
    : targetPlayer(targetPlayer), targetCard(targetCard) {}

void DisenchantmentCommand::execute(Game& game) {
    Player* player = game.getPlayer(targetPlayer);
    if (targetCard == -1) 
    {
        throw runtime_error("Cannot disenchant a ritual. Please target a minion.");
    }

    player->removeEnchantment(targetCard);
}
