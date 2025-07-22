#ifndef VIEW_H
#define VIEW_H

#include "minion.h"
#include "game.h"
#include "hand.h"

class View {
    public:
        View() = default;
        virtual ~View() = default;

        virtual void help() = 0;
        virtual void inspect(const Minion& minion) = 0;
        virtual void showBoard(const Game& game) = 0;
        virtual void showHand(const Hand& hand) = 0;
};

#endif