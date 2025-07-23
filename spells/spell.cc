#include "spell.h"

Spell::Spell(const std::string& name, Player* owner, const std::string& description, int cost)
    : Card(name, owner, description, cost) {}
