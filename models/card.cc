#include "card.h"
#include <utility>

using namespace std;

// constructor
Card::Card(string name, Player* owner, string description, int cost) :
    name(move(name)), owner(owner), description(move(description)), cost(cost) {}

string Card::getName() const {
    return name;
}

Player* Card::getOwner() const {
    return owner;
}

string Card::getDescription() const {
    return description;
}

int Card::getCost() const {
    return cost;
}
