#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <memory>
#include "enums.h"
#include "deck.h"
#include "hand.h"
#include "board.h"
#include "graveyard.h"
#include "game.h"

using namespace std;

class Player {
    string name;
    int magic;
    int health;
    unique_ptr<Deck> deck;
    unique_ptr<Hand> hand;
    unique_ptr<Board> board;
    unique_ptr<Graveyard> graveyard;
    Game* game;

    public:
        Player(const string& name, const string& deckFile, Game* game);
        ~Player() = default;

        string getName() const;
        int getMagic() const;
        int getHealth() const;
        void setMagic(int magic);
        void setHealth(int health);

        void drawCard();
        Card* discardCard(int index);
        Card* playCard(int index);

        Minion* getMinion(int index);
        Game* getGame() const;
        Hand* getHand() const;
        Deck* getDeck() const;
        Board* getBoard() const;
        Graveyard* getGraveyard() const;

        void trigger(Triggers trigger);
};

#endif
