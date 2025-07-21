#ifndef GAME_H
#define GAME_H

#include <string>
#include <memory>
#include "enums.h"
#include "player.h"

using namespace std;

class Game {
    std::unique_ptr<Player> player1;
    std::unique_ptr<Player> player2;
    Player* activePlayer;
    Player* inactivePlayer;

    public:
        Game(string name1, string name2, string deck1File, string deck2File);
        ~Game() = default;
        
        Player* getActivePlayer() const;
        Player* getInactivePlayer() const;
        void switchActivePlayer();
        void endTurn();

        void draw();
        void discard(int index);
        void attack(int index); // minion to player
        void attack(int index, int targetIndex); // minion to minion
        void playCard(int index); // no target
        void playCard(int index, int targetPlayer, char targetCard); // target player and card
        void useMinion(int index); // no target
        void useMinion(int index, int targetPlayer, char targetCard); // target player and card
        void inspectMinion(int index);

        void getHand(); // for display

        void notify(Command* command); // command pattern
        
        void trigger(Triggers trigger);

        Player* getPlayer(int index); // player access
};

#endif
