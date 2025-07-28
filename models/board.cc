#include "board.h"
#include "minion.h"
#include "enchantment.h"
#include "card.h"

Board::Board() : ritual(nullptr) {}

Card* Board::getRitual() {
    return ritual.get();
}

void Board::setRitual(unique_ptr<Card> ritual) {
    this->ritual = move(ritual);
}

void Board::applyEnchantment(std::unique_ptr<Enchantment> ench, int idx) {
    if (idx < 0 || idx >= getSize()) {
        throw std::out_of_range("Invalid minion index for enchantment application");
    }
    auto& slot = cards.at(idx);

    std::unique_ptr<Minion> base(static_cast<Minion*>(slot.release()));
    ench->setNext(std::move(base));

    slot = std::move(ench);
}

void Board::removeEnchantment(int targetMinion) {
    
    auto& slot = cards.at(targetMinion);
    Enchantment* enchantment = dynamic_cast<Enchantment*>(slot.get());
    
    if (enchantment) {
        auto nextMinion = enchantment->releaseNext();
        slot = move(nextMinion);
    }
}

