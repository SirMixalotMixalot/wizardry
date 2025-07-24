#ifndef ABILITIES_H
#define ABILITIES_H

#include "command.h"
#include <string>
#include <memory>

using namespace std;

class Ability {
    string description;

    public:
        Ability(string description); 
        virtual ~Ability() = default;
    
        virtual unique_ptr<Command> use() = 0;
        virtual unique_ptr<Command> use(int player, int targetCard) = 0;
        string getDescription();

};

#endif