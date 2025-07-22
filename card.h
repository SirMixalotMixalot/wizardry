#ifndef CARD_H
#define CARD_H

#include "enums.h"
#include <string>

using namespace std;

class Card {
    string name;
    Player* owner;
    string description;
    int cost;

    public:
        explicit Card(string name, Player* owner, string description, int cost);
        virtual ~Card() = default;

        string getName() const;
        Player* getOwner() const;
        string getDescription() const;
        int getCost() const;
    
        virtual void use() = 0;
        virtual void use(int index, char target) = 0;
        void trigger(Triggers trigger);
    
    private:
        void notifyGame();

};

#endif
