#ifndef HASTE_H
#define HASTE_H

#include "enchantment.h"

class Haste : public Enchantment {
    public:
        Haste(Player* owner, unique_ptr<Minion> next);
        ~Haste() override = default;
        void restoreActions() override;
        void setNext(unique_ptr<Minion> nextMinion) override;
};

#endif
