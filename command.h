#ifndef COMMAND_H
#define COMMAND_H

#include "enums.h"

class Command {
    public:
        virtual ~Command() = default;
        virtual void execute(Game& game) = 0;
};

#endif