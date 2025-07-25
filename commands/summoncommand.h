#ifndef SUMMONCOMMAND_H
#define SUMMONCOMMAND_H

#include <string>
#include "command.h"

class SummonCommand : public Command {
    std::string minionName;
    int minionCount;

    public:
        SummonCommand(const std::string& minionName, int minionCount);
        ~SummonCommand() override = default;

        void execute(Game& game) override;
};

#endif