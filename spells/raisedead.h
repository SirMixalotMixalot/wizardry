#ifndef RAISEDEAD_H
#define RAISEDEAD_H
#include "spell.h"

class RaiseDead : public Spell {
public:
    RaiseDead(Player* owner);
    ~RaiseDead() override = default;

    unique_ptr<Command> use(int player, int targetCard) override;
    unique_ptr<Command> use() override;
};

#endif // RAISEDEAD_H
