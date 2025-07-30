#ifndef TEXTUALDISPLAY_H
#define TEXTUALDISPLAY_H

#include "view.h"
#include "ascii_graphics.h"

class TextualDisplay : public View {
    public:
        TextualDisplay() = default;
        ~TextualDisplay() = default;
        
        void help() override;
        void inspect(const Minion& minion) override;
        void showBoard(const Game& game) override;
        void showHand(const Hand& hand) override;
        void invalidCommand() override;
        void showErrorMessage(const std::string& message) override;
        void showWinner(const std::string& winner) override;
    private:
        void displayTemplate(const card_template_t& templateLines) const;
        card_template_t displayEnchantment(const Enchantment* enchantment) const;
        void displayTemplates(const std::vector<card_template_t>& cards) const;
        card_template_t display_minion(const Minion* minion) const;
};

#endif
