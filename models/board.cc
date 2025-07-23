#include "board.h"
#include "minion.h"
#include "enchantment.h"
void Board::trigger(Triggers trigger) {}

void Board::applyEnchantment(std::unique_ptr<Enchantment> ench, int idx) {
    auto& slot = cards.at(idx);

    std::unique_ptr<Minion> base(static_cast<Minion*>(slot.release()));
    ench->setNext(std::move(base));

    slot = std::move(ench);
}

