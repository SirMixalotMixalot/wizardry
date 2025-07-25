#ifndef ABILITY_H
#define ABILITY_H

#include "command.h"
#include <string>
#include <memory>
#include <stdexcept>

using namespace std;

class Ability {
    string description;

    public:
        Ability(string description); 
        virtual ~Ability() = default;
    
        virtual unique_ptr<Command> use() = 0;
        string getDescription();

};

#endif