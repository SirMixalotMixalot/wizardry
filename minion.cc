#include "minion.h"

using namespace std;

Minion::Minion(string name, Player* owner, string description, int cost, int attack, int defense, int actions)
    : Card(name, owner, description, cost), attack(attack), defense(defense), actions(actions) {}

int Minion::getAttack() const {
    return attack;
}

int Minion::getDefense() const {
    return defense;
}

int Minion::getActions() const {
    return actions;
}

void Minion::setAttack(int attack) {
    this->attack = attack;
}

void Minion::setDefense(int defense) {
    this->defense = defense;
}

void Minion::restoreActions() {
    actions = 1;
}

void Minion::use() {}

void Minion::use(int index, char target) {}
