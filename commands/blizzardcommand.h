#ifndef BLIZZARDCOMMAND_H
#define BLIZZARDCOMMAND_H

#include "command.h"

class BlizzardCommand : public Command {
public:
    BlizzardCommand() = default;
    ~BlizzardCommand() override = default;

    void execute(Game& game) override;
};

#endif
