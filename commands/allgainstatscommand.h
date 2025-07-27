#ifndef ALLGAINSTATSCOMMAND_H
#define ALLGAINSTATSCOMMAND_H

#include "command.h"

class AllGainStatsCommand : public Command {
    int attack;
    int defense;

    public:
        AllGainStatsCommand(int attack, int defense);

        void execute(Game& game) override;
};

#endif