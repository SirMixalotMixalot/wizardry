#include "hand.h"

Hand::Hand() = default;

Hand::~Hand() = default;

bool Hand::isFull() const {
    return cards.size() >= MAX_HAND_SIZE;
}
