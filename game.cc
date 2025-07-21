#include "game.h"
#include <iostream>

using namespace std;

Game::Game(string name1, string name2) {
    player1 = make_unique<Player>(name1);
    cout << "Player 1: " << name1 << endl;
    player2 = make_unique<Player>(name2);
    cout << "Player 2: " << name2 << endl;
    activePlayer = player1.get();
    inactivePlayer = player2.get();
}
