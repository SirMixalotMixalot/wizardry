#ifndef CARD_H
#define CARD_H

#include "enums.h"
#include <string>
#include <memory>

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
    
        virtual unique_ptr<Command> use() = 0;
        virtual unique_ptr<Command> use(int player, int targetCard) = 0;
        void trigger(Triggers trigger);
};

#endif
