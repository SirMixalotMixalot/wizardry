#ifndef BOARD_H
#define BOARD_H

#include "card_collection.h"
#include "enums.h"
#include "ritual.h"

class Board : public CardCollection {
    unique_ptr<Card> ritual;

    public:
        static const int MAX_BOARD_SIZE = 5; // Maximum number of minions on the board
        Board();
        ~Board() override = default;

        void destroyCard(int index);
        Card* getRitual();
        void setRitual(unique_ptr<Card> ritual); 
        void applyEnchantment(std::unique_ptr<Enchantment> enchantment, int minionIndex);
        void removeEnchantment(int targetMinion);
};

#endif
