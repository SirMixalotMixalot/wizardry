#ifndef GAME_H
#define GAME_H

#include <string>
#include <memory>
#include "enums.h"
#include "player.h"
#include "hand.h"

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
        void startTurn();
        void endTurn();

        void draw();
        void discard(int index);
        void attack(int index); // minion to player
        void attack(int index, int targetIndex); // minion to minion
        void playCard(int index); // no target
        /*
            * Play a card from hand.
            * @param index Index of the card in hand.
            * @param targetPlayer Target player index (-1 for no target).
            * @param targetCard Target card index (0-4 for minion, -1 for ritual).
        */
        void playCard(int index, int targetPlayer, int targetCard); // target player and card
        void useMinion(int index); // no target
        void useMinion(int index, int targetPlayer, char targetCard); // target player and card
        Minion* inspectMinion(int index);

        Hand* getHand(); // for display

        void notify(unique_ptr<Command> command); // command pattern
        
        void trigger(Triggers trigger);

        Player* getPlayer(int index); // player access
private:
        void applyEnchantment(unique_ptr<Enchantment> enchantment,int player, int minionIndex);

};

#endif
