#include "hand.h"

bool Hand::isFull() const {
    return cards.size() >= MAX_HAND_SIZE;
}
