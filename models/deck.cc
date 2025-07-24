#include "deck.h"
#include "card.h"
#include <fstream>
#include <iostream>
#include "services/card_factory.h"
#include <memory>

using namespace std;

Deck::Deck(const string& deckFile, Player* owner) : owner(owner) {
    cards.clear();
    ifstream file(deckFile);
    if (!file.is_open()) {
        throw invalid_argument("Could not open deck file: " + deckFile);
    }
    string line;
    while (getline(file, line)) {
        try {
            unique_ptr<Card> card = CardFactory::createCard(line, owner);
            if (card) {
                cards.push_back(move(card));
            } else {
                cerr << "Failed to create card: " << line << endl;
            }
        } catch (const std::invalid_argument& e) {
            cerr << "Error creating card from file: " << e.what() << endl;
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
