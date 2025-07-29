#include "blizzardcommand.h"
#include "game.h"
#include "player.h"
#include "minion.h"
#include "statmodifier.h"
#include <vector>
#include <algorithm>
using namespace std;

void BlizzardCommand::execute(Game& game) {
    Player* activePlayer = game.getActivePlayer();
    vector<int> deadMinions{};
    // iterate through all minions on both players' boards in APNAP order
    for (Player* player : {activePlayer, game.getInactivePlayer()}) {
        deadMinions.clear();
        for (int i = 0; i < player->getBoard()->getSize(); ++i) {
            Minion* minion = player->getMinion(i);
            if (minion) {
                // deal 2 damage to each minion
                // minion->setDefense(minion->getDefense() - 2);
                unique_ptr<StatModifier> defenseModifier = make_unique<StatModifier>(player, nullptr, 0, -2);
                game.applyEnchantment(move(defenseModifier), game.getPlayerNumber(player), i);

                minion = player->getMinion(i); // re-fetch minion after applying enchantment
                if (minion->getDefense() <= 0) {
                    if (minion == game.getLastPlayedMinion()) {
                        game.setLastPlayedMinion(nullptr);
                    }
                    // player->killMinion(i);, i dont want to modify the board while iterating through it
                    deadMinions.push_back(i);
                }
            }
        }
        // now kill all dead minions in order of index
        for (size_t i = 0; i <  deadMinions.size(); ++i) {
            int idx = deadMinions[i] - i;
            player->killMinion(idx);
        }
    }
}
