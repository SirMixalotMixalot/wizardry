#ifndef UNSOMMONCOMMAND_H
#define UNSOMMONCOMMAND_H

#include "command.h"

class UnsummonCommand : public Command {
    int index;
    bool unsummonPlayer1;
public:
    UnsummonCommand(int i, bool player1);
    ~UnsummonCommand() override = default;
    void execute(Game& game) override;
};

#endif // UNSOMMONCOMMAND_H
