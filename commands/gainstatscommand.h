#ifndef GAINSTATSCOMMAND_H
#define GAINSTATSCOMMAND_H

#include "command.h"

class GainStatsCommand : public Command {
    int attack;
    int defense;
    int index;
    Player* owner;

    public:
        GainStatsCommand(int attack, int defense, int index, Player* owner);
        void execute(Game& game) override;
};

#endif