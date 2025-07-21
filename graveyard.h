#ifndef GRAVEYARD_H
#define GRAVEYARD_H

#include "card_collection.h"

class Graveyard : public CardCollection {
    public:
        Graveyard() = default;
        ~Graveyard() override = default;
};

#endif