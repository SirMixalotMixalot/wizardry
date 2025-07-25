#ifndef GAINMAGICCOMMAND_H
#define GAINMAGICCOMMAND_H

#include "command.h"

class GainMagicCommand : public Command {
    int magic;

    public:
        GainMagicCommand(int magic);
        void execute(Game& game) override;
};

#endif