#ifndef ATTACKCOMMAND_H
#define ATTACKCOMMAND_H

#include "command.h"

class AttackCommand : public Command {
    int attackerIndex;
    int targetIndex;

    public:
        AttackCommand(int attackerIndex, int targetIndex = -1);
        void execute(Game& game) override;
};

#endif