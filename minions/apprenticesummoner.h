#ifndef APPRENTICESUMMONER_H
#define APPRENTICESUMMONER_H

#include "minion.h"

class ApprenticeSummoner : public Minion {
    public:
        ApprenticeSummoner(Player* owner);
        ~ApprenticeSummoner() override = default;

        bool canUseAbilities() const override;
};

#endif
