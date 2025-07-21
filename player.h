#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <memory>
#include "enums.h"
#include "deck.h"

using namespace std;

class Player {
    string name;
    int magic;
    int health;
    unique_ptr<Deck> deck;

    public:
        Player(const string& name, const string& deckFile);
        ~Player() = default;

        std::string getName() const;
        int getMagic() const;
        int getHealth() const;
        void setMagic(int magic);
        void setHealth(int health);

        void drawCard();
        Card* discardCard(int index);
        Card* playCard(int index);

        Minion* getMinion(int index);
        Game* getGame();
        Hand* getHand();
        Deck* getDeck();
        Board* getBoard();

        void trigger(Triggers trigger);
};

#endif
