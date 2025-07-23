#ifndef BONEGolem_H
#define BONEGolem_H
#include "minion.h"
class BoneGolem : public Minion {
    public:
        BoneGolem(Player* owner);
        ~BoneGolem() override = default;

        bool canUseAbilities() const override;
};
#endif
