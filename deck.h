#ifndef DECK_H
#define DECK_H

#include <vector>
#include "card.h"
#include <memory>
using namespace std;

class Deck {
    vector<unique_ptr<Card>> cards;
    Player* owner;

    public:
        Deck(const string& deckFile, Player* owner);
        ~Deck() = default;

        unique_ptr<Card> draw();
        void shuffle();
        bool isEmpty() const;
};

#endif
