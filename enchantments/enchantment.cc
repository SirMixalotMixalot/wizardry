#include "enchantment.h"

using namespace std;

Enchantment::Enchantment(string name, Player* owner, string description, int cost, string attackModifier, string defenseModifier, unique_ptr<Minion> next, bool displayable) : Minion(name, owner, description, cost, 0, 0, nullptr), attackModifier(attackModifier), defenseModifier(defenseModifier), next(std::move(next)), displayable(displayable) {}

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

TriggeredAbility* Enchantment::getTriggeredAbility() const {
    return next->getTriggeredAbility();
}

ActivatedAbility* Enchantment::getActivatedAbility() const {
    return next->getActivatedAbility();
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

void Enchantment::setNext(unique_ptr<Minion> nextMinion) {
    next = std::move(nextMinion);
}

const Minion* Enchantment::getNext() const {
    return next.get();
}

unique_ptr<Minion> Enchantment::releaseNext() {
    return move(next);
}

bool Enchantment::displayableEnchantment() const {
    return displayable;
}

std::unique_ptr<Minion>& Enchantment::ownNext()
{ 
    return next;
}
