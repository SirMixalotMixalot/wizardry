#include "player.h"
#include <iostream>

Player::Player(const string& name) {
    this->name = name;
    magic = 3;
    health = 20;
}
