#ifndef DISENCHANTMENT_H
#define DISENCAHNTMENT_H

#include "spell.h"

class Disenchantment : public Spell 
{
public:
    Disenchantment(Player* owner);
    unique_ptr<Command> use(int targetPlayer, int targetCard) override;
    unique_ptr<Command> use() override;
};

#endif
