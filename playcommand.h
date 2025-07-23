#ifndef PLAYCOMMAND_H
#define PLAYCOMMAND_H

#include "command.h"
#include <string>
#include <vector>

class PlayCommand : public Command {
    int cardIndex;
    int playerIndex;
    int targetIndex;

    public:
        PlayCommand(int cardIndex, int playerIndex = -1, int targetIndex = -1);
        void execute(Game& game) override;
};

#endif
