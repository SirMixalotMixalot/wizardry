#ifndef RAISEDEADCOMMAND_H
#define RAISEDEADCOMMAND_H

#include "command.h"

class RaiseDeadCommand : public Command {
public:
    RaiseDeadCommand() = default;
    ~RaiseDeadCommand() override = default;

    void execute(Game& game) override;
};

#endif // RAISEDEADCOMMAND_H
