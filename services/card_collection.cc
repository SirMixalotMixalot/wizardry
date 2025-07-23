#include "card_collection.h"
#include <stdexcept>
#include <utility>

using namespace std;

CardCollection::~CardCollection() = default;

void CardCollection::addCard(unique_ptr<Card> card) {
    cards.push_back(move(card));
}

unique_ptr<Card> CardCollection::removeCard(int index) {
    if (index < 0 || index >= cards.size()) {
        throw invalid_argument("index out of range");
    }
    unique_ptr<Card> card = move(cards[index]);
    cards.erase(cards.begin() + index);
    return card;
}


Card* CardCollection::getCard(int index) const {
    if (index < 0 || index >= cards.size()) {
        return nullptr;
    }
    return cards[index].get();
}

int CardCollection::getSize() const {
    return cards.size();
}
