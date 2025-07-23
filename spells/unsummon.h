#ifndef UNSUMMON_H
#define UNSUMMON_H

#include "spell.h"
#include <memory>

class Unsummon : public Spell {
public:
    Unsummon(Player* owner);
    ~Unsummon() override = default;

    unique_ptr<Command> use(int index, int target) override;
    unique_ptr<Command> use() override; 
};

#endif // UNSUMMON_H
