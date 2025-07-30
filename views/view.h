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
        virtual void invalidCommand() = 0;
        virtual void showErrorMessage(const std::string& message) = 0;
        virtual void showWinner(const std::string& winner) = 0;
        virtual void showActivePlayer(const Game& game) const = 0;

};

#endif
