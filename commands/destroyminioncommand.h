#ifndef DESTROYMINIONCOMMAND_H
#define DESTROYMINIONCOMMAND_H

#include "command.h"

class DestroyMinionCommand : public Command {
    Player* owner;

    public:
        DestroyMinionCommand(Player* owner);
        void execute(Game& game) override;
};

#endif