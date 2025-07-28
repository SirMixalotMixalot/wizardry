#include "minion.h"

using namespace std;

Minion::Minion(string name, Player* owner, string description, int cost, int attack, int defense, unique_ptr<ActivatedAbility> activatedAbility, unique_ptr<TriggeredAbility> triggeredAbility)
    : Card(name, owner, description, cost), attack(attack), defense(defense), actions(0), activatedAbility(move(activatedAbility)), triggeredAbility(move(triggeredAbility)) {}

int Minion::getAttack() const {
    return attack;
}

int Minion::getDefense() const {
    return defense;
}

int Minion::getActions() const {
    return actions;
}

TriggeredAbility* Minion::getTriggeredAbility() const {
    return triggeredAbility.get();
}

ActivatedAbility* Minion::getActivatedAbility() const {
    return activatedAbility.get();
}

int Minion::getActivatedAbilityCost() const {
    if (!activatedAbility) {
        throw runtime_error("Selected minion has no activated ability.");
    }
    return activatedAbility->getCost();
}

void Minion::setAttack(int attack) {
    this->attack = attack;
}

void Minion::setDefense(int defense) {
    this->defense = defense;
}

void Minion::setActions(int actions) {
    this->actions = actions;
}

void Minion::restoreActions() {
    actions = 1;
}

unique_ptr<Command> Minion::use() {
    if (!activatedAbility) {
        throw runtime_error("Selected minion has no activated ability.");
    }
    return activatedAbility->use(); // Use the activated ability
}

unique_ptr<Command> Minion::use(int index, int target) {
    if (!activatedAbility) {
        throw runtime_error("Selected minion has no activated ability.");
    }
    return activatedAbility->use(index, target); // Use the activated ability with parameters
}
