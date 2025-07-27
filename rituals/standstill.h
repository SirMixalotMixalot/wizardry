#ifndef STANDSTILL_H
#define STANDSTILL_H

#include "ritual.h"

class Standstill: public Ritual {
    public:
        Standstill(Player* owner);
        ~Standstill() override = default;
};

#endif
