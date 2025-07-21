#include "deck.h"
#include "card.h"
#include <fstream>
#include <iostream>

using namespace std;

Deck::Deck(const string& deckFile) {
    cards.clear();
    
    ifstream file(deckFile);
    string line;
    while (getline(file, line)) {
        // create card objects when needed
        cout << line << endl;
    }
    
    file.close();
}

unique_ptr<Card> Deck::draw() {
    if (isEmpty()) {
        return nullptr;
    } else {
        unique_ptr<Card> card = move(cards.back());
        cards.pop_back();
        return card;
    }
}

void Deck::shuffle() {}


bool Deck::isEmpty() const {
    return cards.empty();
}
