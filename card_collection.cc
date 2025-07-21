#include "card_collection.h"
#include <stdexcept>
#include <utility>

using namespace std;

CardCollection::~CardCollection() = default;

void CardCollection::addCard(unique_ptr<Card> card) {
    cards.push_back(move(card));
}

void CardCollection::removeCard(int index) {
    if (index < 0 || index >= getSize()) {
        throw out_of_range("Index out of range");
    }
    cards.erase(cards.begin() + index);
}


Card* CardCollection::getCard(int index) const {
    if (index < 0 || index >= getSize()) {
        throw out_of_range("Index out of range");
    }
    return cards[index].get();
}

int CardCollection::getSize() const {
    return cards.size();
}