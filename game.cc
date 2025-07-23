#include "game.h"
#include "command.h"
#include "minion.h"
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

Player* Game::getPlayer(int index) {
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
    // start of turn effects trigger
}

void Game::endTurn() {
    // end of turn effects trigger
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
    }
}

void Game::attack(int index, int targetIndex) {
    Minion* minion = activePlayer->getMinion(index);
    Minion* target = inactivePlayer->getMinion(targetIndex);
    if (minion != nullptr && target != nullptr && minion->getActions() > 0) {
        minion->setActions(minion->getActions() - 1);
        target->setDefense(target->getDefense() - minion->getAttack());
        minion->setDefense(minion->getDefense() - target->getAttack());
        if (target->getDefense() <= 0) {
            inactivePlayer->getGraveyard()->addCard(inactivePlayer->getBoard()->removeCard(targetIndex));
        }
        if (minion->getDefense() <= 0) {
            activePlayer->getGraveyard()->addCard(activePlayer->getBoard()->removeCard(index));
        }
    } 
}

void Game::playCard(int index) {
    activePlayer->playCard(index);
}

void Game::playCard(int index, int targetPlayer, char targetCard) {}

void Game::useMinion(int index) {}

void Game::useMinion(int index, int targetPlayer, char targetCard) {}

Minion* Game::inspectMinion(int index) {}

Hand* Game::getHand() {
    return activePlayer->getHand();
}

void Game::notify(unique_ptr<Command> command) {
    command->execute(*this);
}

void Game::trigger(Triggers trigger) {}
