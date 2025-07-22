#ifndef MASTERSUMMONER_H
#define MASTERSUMMONER_H

#include "../minion.h"

class MasterSummoner : public Minion {
    public:
        MasterSummoner(Player* owner);
        ~MasterSummoner() override = default;

        bool canUseAbilities() const override;
};

#endif
