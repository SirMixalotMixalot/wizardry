#ifndef DECK_H
#define DECK_H

#include <vector>
#include "card.h"

using namespace std;

class Deck {
    vector<unique_ptr<Card>> cards;

    public:
        Deck(const string& deckFile);
        ~Deck() = default;

        unique_ptr<Card> draw();
        void shuffle();
        bool isEmpty() const;
};

#endif
