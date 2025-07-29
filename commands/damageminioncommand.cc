#include "damageminioncommand.h"
#include "game.h"
#include "minion.h"
#include "statmodifier.h"

DamageMinionCommand::DamageMinionCommand(int target, bool player1, int damage) : targetCard(target), damagePlayer1(player1), damage(damage) {}

void DamageMinionCommand::execute(Game& game) {
    Player* targetPlayer = damagePlayer1 ? game.getPlayer(1) : game.getPlayer(2);

    if (targetCard < 0 || targetCard >= targetPlayer->getBoard()->getSize()) {
        throw std::out_of_range("Invalid index for damaging a minion.");
    }

    Minion* minion = targetPlayer->getMinion(targetCard);
    if (!minion) {
        throw std::runtime_error("No minion found at the specified index.");
    }

    // Apply damage to the minion, kill if defense is less than or equal to 0
    // minion->setDefense(minion->getDefense() - damage);
    unique_ptr<StatModifier> defenseModifier = make_unique<StatModifier>(targetPlayer, nullptr, 0, -damage);
    game.applyEnchantment(move(defenseModifier), game.getPlayerNumber(targetPlayer), targetCard);
    
    minion = targetPlayer->getMinion(targetCard); // re-fetch minion after applying enchantment
    if (minion->getDefense() <= 0) {
        targetPlayer->killMinion(targetCard);
    }
}