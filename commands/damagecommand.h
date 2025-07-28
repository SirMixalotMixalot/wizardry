#ifndef DAMAGECOMMAND_H
#define DAMAGECOMMAND_H

#include "command.h"

class DamageCommand : public Command {
    Player* owner;
    int damage;
    
    public:
        DamageCommand(Player* owner, int damage);
        void execute(Game& game) override;
};

#endif