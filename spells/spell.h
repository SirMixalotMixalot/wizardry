#ifndef SPELL_H
#define SPELL_H

#include "card.h"
#include <memory>
#include <command.h>
class Spell : public Card {
public:
    Spell(const std::string& name, Player* owner, const std::string& description, int cost);

    unique_ptr<Command> use() override = 0;
    unique_ptr<Command> use(int player, int targetCard) override = 0;
};

#endif // SPELL_H
