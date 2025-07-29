#ifndef DISENCHANTMENT_H
#define DISENCHANTMENT_H

#include "spell.h"

class Disenchantment : public Spell 
{
public:
    Disenchantment(Player* owner);
    unique_ptr<Command> use(int targetPlayer, int targetCard) override;
    unique_ptr<Command> use() override;
};

#endif
