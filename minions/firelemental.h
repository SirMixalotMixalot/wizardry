#ifndef FIRELEMENTAL_H
#define FIRELEMENTAL_H

#include "../minion.h"
class FireElemental : public Minion {
    public:
        FireElemental(Player* owner);
        ~FireElemental() override = default;

        bool canUseAbilities() const override;
};

#endif
