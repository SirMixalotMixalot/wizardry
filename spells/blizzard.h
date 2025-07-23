#ifndef Blizzard_H
#define Blizzard_H

#include "spell.h"

class Blizzard : public Spell {
public: 
    Blizzard(Player* owner);
    ~Blizzard() override = default;
    unique_ptr<Command> use() override;

    unique_ptr<Command> use(int player, int targetChild) override;
};

#endif // Blizzard_H
