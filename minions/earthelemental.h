#ifndef EARTHELEMENTAL_H
#define EARTHELEMENTAL_H

#include "../minion.h"

class EarthElemental : public Minion {
    public:
        EarthElemental(Player* owner);
        ~EarthElemental() override = default;

        bool canUseAbilities() const override;
};

#endif
