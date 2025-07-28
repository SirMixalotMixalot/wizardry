#ifndef DARKRITUAL_H
#define DARKRITUAL_H

#include "ritual.h"

class DarkRitual : public Ritual {
    public:
        DarkRitual(Player* owner);
        ~DarkRitual() override = default;
};

#endif