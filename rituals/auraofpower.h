#ifndef AURAOFPOWER_H
#define AURAOFPOWER_H

#include "ritual.h"

class AuraOfPower : public Ritual {
    public:
        AuraOfPower(Player* owner);
        ~AuraOfPower() override = default;
};

#endif
