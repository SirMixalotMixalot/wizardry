#include "applyenchantmentcommand.h"
#include "game.h"
#include "enchantment.h"

ApplyEnchantmentCommand::ApplyEnchantmentCommand(int targetPlayer, int targetCard, unique_ptr<Enchantment> enchantment)
    : targetPlayer(targetPlayer), targetCard(targetCard), enchantment(std::move(enchantment)) {}

void ApplyEnchantmentCommand::execute(Game& game) {
    if (targetPlayer < 1 || targetPlayer > 2 || targetCard < -1 || targetCard > 4) {
        throw std::invalid_argument("Invalid target player or card index");
    }
    
    game.applyEnchantment(std::move(enchantment), targetPlayer, targetCard);
}
