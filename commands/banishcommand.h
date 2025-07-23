#ifndef BANISHCOMMAND_H
#define BANISHCOMMAND_H

#include "command.h"

class BanishCommand : public Command {
    int targetCard; // -1 for ritual, 0-4 for minion index
    bool banishPlayer1;
public:

    BanishCommand(int target, bool player1);
    ~BanishCommand() override = default;

    void execute(Game& game) override;
};

#endif // BANISHCOMMAND_H

