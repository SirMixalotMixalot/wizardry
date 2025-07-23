#ifndef HAND_H
#define HAND_H

#include "card_collection.h"

class Hand : public CardCollection {
    static const int MAX_HAND_SIZE = 5;

    public:
        Hand() = default;
        ~Hand() override = default;
        bool isFull() const;
};

#endif