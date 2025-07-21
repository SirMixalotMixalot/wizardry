#include "game.h"
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
    // start of turn effects trigger
}

void Game::endTurn() {
    // end of turn effects trigger
    switchActivePlayer();
}

void Game::draw() {
    // not sure if we need this one
}

void Game::discard(int index) {}

void Game::attack(int index) {}

void Game::attack(int index, int targetIndex) {}

void Game::playCard(int index) {}

void Game::playCard(int index, int targetPlayer, char targetCard) {}

void Game::useMinion(int index) {}

void Game::useMinion(int index, int targetPlayer, char targetCard) {}

Minion* Game::inspectMinion(int index) {}

Hand* Game::getHand() {
    return activePlayer->getHand();
}

void Game::notify(Command* command) {}

void Game::trigger(Triggers trigger) {}
