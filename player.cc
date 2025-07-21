#include "player.h"
#include <iostream>

Player::Player(const string& name, const string& deckFile) {
    this->name = name;
    magic = 3;
    health = 20;
    deck = make_unique<Deck>(deckFile);
}
