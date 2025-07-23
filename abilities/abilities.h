#ifndef ABILITIES_H
#define ABILITIES_H

#include <string>

using namespace std;

class Ability {
    string description;

    public:
        Ability(string description); 
        ~Ability() = default;
    
        virtual void use() = 0;
        string getDescription();

};

#endif