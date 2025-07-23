#ifndef AIRELEMENTAL_H
#define AIRELEMENTAL_H

#include "minion.h"

class AirElemental : public Minion {
    public:
        AirElemental(Player* owner);
        ~AirElemental() override = default;

        bool canUseAbilities() const override;
};

#endif
