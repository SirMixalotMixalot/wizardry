#ifndef DECK_H
#define DECK_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Deck {
    vector<string> cards;

    public:
        Deck(const string& deckFile);
        ~Deck() = default;

        void shuffle();
        bool isEmpty() const;
};

#endif
