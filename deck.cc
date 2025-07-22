#include "deck.h"
#include "card.h"
#include <fstream>
#include <iostream>
#include "airelemental.h"
#include "earthelemental.h"

using namespace std;

Deck::Deck(const string& deckFile, Player* owner) : owner(owner) {
    cards.clear();
    
    ifstream file(deckFile);
    string line;
    while (getline(file, line)) {
        if (line == "Air Elemental") {
            cards.push_back(make_unique<AirElemental>(owner));
        } else if (line == "Earth Elemental") {
            cards.push_back(make_unique<EarthElemental>(owner));
        } else {
            
        }
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
