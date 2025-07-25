#ifndef APPLY_ENCHANTMENT_H
#define APPLY_ENCHANTMENT_H
#include "command.h"
#include "memory"
using namespace std;
class ApplyEnchantmentCommand : public Command {
    int targetPlayer; // 1 or 2
    int targetCard; // -1 for ritual, 0-4 for minion index
    unique_ptr<Enchantment> enchantment;

    public:
        ApplyEnchantmentCommand(int targetPlayer, int targetCard, unique_ptr<Enchantment> enchantment);
        void execute(Game& game) override;
};




#endif
