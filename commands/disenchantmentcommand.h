#ifndef DISENCHANTMENTCOMMAND_H
#define DISENCHANTMENTCOMMAND_H


#include "command.h"
#include "enchantment.h"

class DisenchantmentCommand : public Command {
    int targetPlayer; // 1 or 2
    int targetCard; // -1 for ritual, 0-4 for minion index
public:
    DisenchantmentCommand(int targetPlayer, int targetCard);

    void execute(Game& game) override;
};
#endif // DISENCHANTMENTCOMMAND_H
