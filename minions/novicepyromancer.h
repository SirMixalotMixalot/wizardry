#ifndef NOVICEPYROMANCER_H
#define NOVICEPYROMANCER_H
#include "../minion.h"

class NovicePyromancer : public Minion {
    public:
        NovicePyromancer(Player* owner);
        ~NovicePyromancer() override = default;

        bool canUseAbilities() const override;
};
#endif // NOVICEPYROMANCER_H
