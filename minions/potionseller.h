#ifndef POTIONSSELLER_H
#define POTIONSSELLER_H
#include "../minion.h"

class PotionSeller : public Minion {
    public:
        PotionSeller(Player* owner);
        ~PotionSeller() override = default;

        bool canUseAbilities() const override;
};


#endif // POTIONSSELLER_H
