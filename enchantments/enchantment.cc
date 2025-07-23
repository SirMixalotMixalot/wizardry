#include "enchantment.h"

using namespace std;

Enchantment::Enchantment(string name, Player* owner, string description, int cost, string attackModifier, string defenseModifier, Minion* next) : Minion(name, owner, description, cost, 0, 0), attackModifier(attackModifier), defenseModifier(defenseModifier), next(next) {}

Enchantment::~Enchantment() = default;

string Enchantment::getAttackModifier() const {
    return attackModifier;
}

string Enchantment::getDefenseModifier() const {
    return defenseModifier;
}

unique_ptr<Command> Enchantment::use() {
    return next->use();
}

unique_ptr<Command> Enchantment::use(int index, int target) {
    return next->use(index, target);
}

void Enchantment::restoreActions() {
    next->restoreActions();
}

int Enchantment::getAttack() const {
    return next->getAttack();
}

int Enchantment::getDefense() const {
    return next->getDefense();
}

int Enchantment::getActions() const {
    return next->getActions();
}

int Enchantment::getActivatedAbilityCost() const {
    return next->getActivatedAbilityCost();
}

bool Enchantment::canUseAbilities() const {
    return next->canUseAbilities();
}

void Enchantment::setAttack(int attack) {
    next->setAttack(attack);
}

void Enchantment::setDefense(int defense) {
    next->setDefense(defense);
}

void Enchantment::setActions(int actions) {
    next->setActions(actions);
}

void Enchantment::setNext(Minion* nextMinion) {
    next = nextMinion;
}
