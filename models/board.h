#ifndef BOARD_H
#define BOARD_H

#include "card_collection.h"
#include "enums.h"
#include "ritual.h"

class Board : public CardCollection {
    unique_ptr<Card> ritual;

    public:
        Board();
        ~Board() override = default;

        Card* getRitual();
        void setRitual(unique_ptr<Card> ritual); 
        void applyEnchantment(std::unique_ptr<Enchantment> enchantment, int minionIndex);
};

#endif
