#include "statsetter.h"

StatSetter::StatSetter(Player* owner, unique_ptr<Minion> next, int attack, int defense)
    : Enchantment("Stat Setter", owner, "", 0, "", "", std::move(next), false), attack(attack), defense(defense) {}

int StatSetter::getAttack() const {
    return attack;
}

int StatSetter::getDefense() const {
    return defense;
}