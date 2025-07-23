#ifndef TEXTUALDISPLAY_H
#define TEXTUALDISPLAY_H

#include "view.h"

class TextualDisplay : public View {
    public:
        TextualDisplay() = default;
        ~TextualDisplay() = default;
        
        void help() override;
        void inspect(const Minion& minion) override;
        void showBoard(const Game& game) override;
        void showHand(const Hand& hand) override;
        void invalidCommand() override;
};

#endif