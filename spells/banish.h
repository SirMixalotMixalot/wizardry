#ifndef BANISH_H
#define BANISH_H

#include "spell.h"

class Banish : public Spell {
public:
    Banish(Player* owner);
    ~Banish() override = default;
    unique_ptr<Command> use(int player, int targetCard) override;
    unique_ptr<Command> use() override;
};

#endif // BANISH_H
