#include "game.h"
#include <iostream>

using namespace std;

Game::Game(string name1, string name2, string deck1File, string deck2File) {
    player1 = make_unique<Player>(name1, deck1File);
    player2 = make_unique<Player>(name2, deck2File);
    activePlayer = player1.get();
    inactivePlayer = player2.get();
}
