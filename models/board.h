#ifndef BOARD_H
#define BOARD_H

#include "card_collection.h"
#include "enums.h"

class Board : public CardCollection {
    public:
        Board() = default;
        ~Board() override = default;
        
        void trigger(Triggers trigger);
        void applyEnchantment(std::unique_ptr<Enchantment> enchantment, int minionIndex);
};

#endif
