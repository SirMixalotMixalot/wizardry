#ifndef BANISHCOMMAND_H
#define BANISHCOMMAND_H

#include "command.h"

class BanishCommand : public Command {
    int index;
    bool banishPlayer1;
public:

    BanishCommand(int i, bool player1);
    ~BanishCommand() override = default;

    void execute(Game& game) override;
};

#endif // BANISHCOMMAND_H

