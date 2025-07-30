#include "game.h"
#include "command.h"
#include "minion.h"
#include "player.h"
#include "enchantment.h"
#include "statmodifier.h"
#include "actionsmodifier.h"
#include <memory>
#include <iostream>

using namespace std;

Game::Game(string name1, string name2, string deck1File, string deck2File) {
    player1 = make_unique<Player>(name1, deck1File, this);
    player2 = make_unique<Player>(name2, deck2File, this);
    activePlayer = player1.get();
    inactivePlayer = player2.get();
}

Player* Game::getActivePlayer() const {
    return activePlayer;
}

Player* Game::getInactivePlayer() const {
    return inactivePlayer;
}

int Game::getPlayerNumber(Player* player) const {
    return (player == player1.get()) ? 1 : 2;
}

Player* Game::getPlayer(int index) const {
    if (index == 1) {
        return player1.get();
    } else if (index == 2) {
        return player2.get();
    } else {
        throw invalid_argument("Invalid player index");
    }
}

void Game::switchActivePlayer() {
    Player* temp = activePlayer;
    activePlayer = inactivePlayer;
    inactivePlayer = temp;
}

void Game::startTurn() {
    activePlayer->setMagic(activePlayer->getMagic() + 1);
    activePlayer->drawCard();
    for (int i = 0; i < activePlayer->getBoard()->getSize(); i++) {
        if (activePlayer->getMinion(i)) {
            activePlayer->getMinion(i)->restoreActions();
        }
    }
    trigger(Triggers::START_OF_TURN);
}

void Game::endTurn() {
    // end of turn effects trigger
    trigger(Triggers::END_OF_TURN);
    switchActivePlayer();
}

void Game::draw() {
    activePlayer->drawCard();
}

void Game::discard(int index) {
    activePlayer->discardCard(index);
}

void Game::attack(int index) {
    Minion* minion = activePlayer->getMinion(index);
    if (minion != nullptr && minion->getActions() > 0) {
        inactivePlayer->setHealth(inactivePlayer->getHealth() - minion->getAttack());
        minion->setActions(minion->getActions() - 1);
        // unique_ptr<ActionsModifier> actionsModifier = make_unique<ActionsModifier>(activePlayer, nullptr, -1);
        // int playerNumber = getPlayerNumber(activePlayer);
        // applyEnchantment(move(actionsModifier), playerNumber, index);
    }
}

void Game::attack(int index, int targetIndex) {
    Minion* minion = activePlayer->getMinion(index);
    Minion* target = inactivePlayer->getMinion(targetIndex);
    if (minion != nullptr && target != nullptr && minion->getActions() > 0) {
        minion->setActions(minion->getActions() - 1);
        // unique_ptr<ActionsModifier> actionsModifier = make_unique<ActionsModifier>(activePlayer, nullptr, -1);
        // applyEnchantment(move(actionsModifier), getPlayerNumber(activePlayer), index);

        // target->setDefense(target->getDefense() - minion->getAttack());
        // minion->setDefense(minion->getDefense() - target->getAttack());
        unique_ptr<StatModifier> targetDefenseModifier = make_unique<StatModifier>(inactivePlayer, nullptr, 0, -minion->getAttack());
        applyEnchantment(move(targetDefenseModifier), getPlayerNumber(inactivePlayer), targetIndex);
        unique_ptr<StatModifier> minionDefenseModifier = make_unique<StatModifier>(activePlayer, nullptr, 0, -target->getAttack());
        applyEnchantment(move(minionDefenseModifier), getPlayerNumber(activePlayer), index);

        minion = activePlayer->getMinion(index);
        target = inactivePlayer->getMinion(targetIndex);
        // apnap order
        if (minion->getDefense() <= 0) {
            activePlayer->killMinion(index);
        }
        if (target->getDefense() <= 0) {
            inactivePlayer->killMinion(targetIndex);
        }
    } 
}

void Game::playCard(int index) {
    activePlayer->playCard(index);
}

void Game::playCard(int index, int targetPlayer, int targetCard) {
    activePlayer->playCard(index, targetPlayer, targetCard);
}

void Game::useMinion(int index) {
    Minion* minion = activePlayer->getMinion(index);
    if (minion != nullptr && minion->canUseAbilities() && minion->getActions() > 0 && activePlayer->getMagic() >= minion->getActivatedAbilityCost()) {
        unique_ptr<Command> command = minion->use();
        notify(move(command)); // call Game.notify with the command
        minion->setActions(minion->getActions() - 1);
        activePlayer->setMagic(activePlayer->getMagic() - minion->getActivatedAbilityCost());
    } 
    else {
        throw runtime_error("Selected minion cannot use abilities or has no actions left.");
    }
}

void Game::useMinion(int index, int targetPlayer, int targetCard) { // NOTE: This method shares a lot of code with the previous one and can probably be combined in the future.
    Minion* minion = activePlayer->getMinion(index);
    if (minion != nullptr && minion->canUseAbilities() && minion->getActions() > 0 && activePlayer->getMagic() >= minion->getActivatedAbilityCost()) {
        unique_ptr<Command> command = minion->use(targetPlayer, targetCard);
        notify(move(command)); // call Game.notify with the command
        minion->setActions(minion->getActions() - 1);
        activePlayer->setMagic(activePlayer->getMagic() - minion->getActivatedAbilityCost());
    } 
    else {
        throw runtime_error("Selected minion cannot use abilities or has no actions left.");
    }
}

Minion* Game::getLastPlayedMinion() {
    return lastPlayedMinion;
}

void Game::setLastPlayedMinion(Minion* minion) {
    lastPlayedMinion = minion;
}

Hand* Game::getHand() {
    return activePlayer->getHand();
}

void Game::notify(unique_ptr<Command> command) {
    command->execute(*this);
}

void Game::trigger(Triggers trigger) {
    activePlayer->trigger(trigger);
    if (trigger == Triggers::MINION_ENTERS_PLAY || trigger == Triggers::MINION_LEAVES_PLAY) {
        inactivePlayer->trigger(trigger);
    }
}

void Game::applyEnchantment(std::unique_ptr<Enchantment> ench, int player, int idx) {
    Player* targetPlayer = getPlayer(player);
    bool lastFlag = false;
    if (targetPlayer->getMinion(idx) == lastPlayedMinion) {
        lastFlag = true;
    }
    targetPlayer->getBoard()->applyEnchantment(std::move(ench), idx);
    if (lastFlag) {
        lastPlayedMinion = targetPlayer->getMinion(idx);
    }
}

