#ifndef RECHARGE_COMMAND_H
#define RECHARGE_COMMAND_H

#include "command.h"
#include "game.h"

class RechargeCommand : public Command {
public:
    RechargeCommand() = default;

    void execute(Game& game) override;
};

#endif
