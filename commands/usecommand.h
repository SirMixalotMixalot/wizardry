#ifndef USECOMMAND_H
#define USECOMMAND_H

#include "command.h"
#include <string>
#include <vector>

class UseCommand : public Command {
    int cardIndex;
    int playerIndex;
    int targetIndex;

    public:
        UseCommand(int cardIndex, int playerIndex = -1, int targetIndex = -1);
        void execute(Game& game) override;
};

#endif
