#ifndef DAMAGEMINIONCOMMAND_H
#define DAMAGEMINIONCOMMAND_H

#include "command.h"

class DamageMinionCommand : public Command {
    int targetCard; // Stores 0-4 for minion index
    bool damagePlayer1;

    public:
        DamageMinionCommand(int target, bool player1);
        ~DamageMinionCommand() override = default;

        void execute(Game& game) override;
};

#endif