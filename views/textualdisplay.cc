#include "textualdisplay.h"
#include "enchantment.h"
#include "spell.h"
#include "minion.h"
#include <iostream>
#include "ascii_graphics.h"
#include <algorithm>
#include <sstream>
#include "game.h"
using namespace std;

void TextualDisplay::displayTemplate(const card_template_t& templateLines) const {
    for (const auto& line : templateLines) {
        cout << line << endl;
    }
}
void TextualDisplay::displayTemplates(const std::vector<card_template_t>& cards) const {
    const auto MAX_PER_ROW = 5;

    for (auto start = 0; start < cards.size(); start += MAX_PER_ROW) {
        auto end = cards.size() <= start + MAX_PER_ROW ? cards.size() : start + MAX_PER_ROW;
        auto nLines = cards[start].size();

        for (auto line = 0; line < nLines; ++line) {
            for (auto idx = start; idx < end; ++idx) {
                std::cout << cards[idx][line];
            }
            std::cout << '\n';
        }
        std::cout << '\n';
    }
}


void TextualDisplay::help() {
    cout << "Commands:" << endl;
    cout << "   help -- Display this message" << endl;
    cout << "   end -- End this current player's turn" << endl;
    cout << "   quit -- End the game" << endl;
    cout << "   attack minion other-minion -- Orders minion to attack other-minion" << endl;
    cout << "   attack minion -- Orders minion to attack the opponent" << endl;
    cout << "   play card [target-player target-card] -- Play card, optionally targeting target-card owned by target-player" << endl;
    cout << "   use minion [target-player target-card] -- Use minion's special ability, optionally targeting target-card owned by target-player" << endl;
    cout << "   inspect minion -- View a minion's card and all enchantments on that minion" << endl;
    cout << "   hand -- Describe all cards in your hand" << endl;
    cout << "   board -- Describe all cards on the board" << endl;
}


void TextualDisplay::inspect(const Minion& minion) {

    const Enchantment* current = dynamic_cast<const Enchantment*>(&minion);
    if (!current) {
        // print minion normally
        auto card = display_minion(&minion);
        displayTemplate(card);
        return;
    }
    vector<card_template_t> enchantmentLines;
    const Minion* nextMinion = current->getNext();
    while (current) {

        // create current enchantment template and then display it
        if (current->displayableEnchantment()) {
            card_template_t enchantmentTemplate = displayEnchantment(current);
            enchantmentLines.push_back(enchantmentTemplate);
        }
        // move to the next enchantment
        nextMinion =  current->getNext();
        current = dynamic_cast<const Enchantment*>(nextMinion);
        
    }

    // print minion
    auto card = display_minion(&minion);
    displayTemplate(card);
    // print enchantments in reverse order
    std::vector<card_template_t> reversed(enchantmentLines.rbegin(), enchantmentLines.rend());
    displayTemplates(reversed);

}

static std::vector<std::string>
flattenRow(const std::vector<card_template_t>& row) {
    const size_t MAX_PER_ROW = 5;
    const int CARD_HEIGHT = CARD_TEMPLATE_EMPTY.size();
    std::vector<std::string> out;

    for (size_t start = 0; start < row.size(); start += MAX_PER_ROW) {
        size_t end = std::min(row.size(), start + MAX_PER_ROW);

        
        for (size_t ln = 0; ln < CARD_HEIGHT; ++ln) {
            std::ostringstream line;
            for (size_t i = start; i < end; ++i) {
                const auto& card = row[i];
                line << card[ln];
            }
            out.push_back(line.str());
        }
    }
    return out;
}

static void printTopBorder(size_t width) {
    std::cout << EXTERNAL_BORDER_CHAR_TOP_LEFT;
    for (auto i = 0; i < width; ++i) {
        std::cout << EXTERNAL_BORDER_CHAR_LEFT_RIGHT;
    }
    cout << EXTERNAL_BORDER_CHAR_TOP_RIGHT << "\n";
}

static void printBottomBorder(size_t width) {
    std::cout << EXTERNAL_BORDER_CHAR_BOTTOM_LEFT;
    for (auto i = 0; i < width; ++i) {
        std::cout << EXTERNAL_BORDER_CHAR_LEFT_RIGHT;
    }
    cout << EXTERNAL_BORDER_CHAR_BOTTOM_RIGHT << "\n";
}

static void printLineWithBorders(const std::string& content, size_t width) {
    std::cout << EXTERNAL_BORDER_CHAR_UP_DOWN
              << content
              << EXTERNAL_BORDER_CHAR_UP_DOWN << "\n";
}

card_template_t TextualDisplay::display_minion(const Minion* minion) const {
    // if the minion is in enchanted, get the attack and defense from the enchanted minion but then display regularly
    int attack = minion->getAttack();
    int defense = minion->getDefense();

    while (auto enchantment = dynamic_cast<const Enchantment*>(minion)) {
        minion = enchantment->getNext();
    }

    if (minion->getActivatedAbility()) {
        return display_minion_activated_ability(minion->getName(), minion->getCost(), attack, defense,
        minion->getActivatedAbilityCost(), minion->getActivatedAbility()->getDescription());
    } else if (minion->getTriggeredAbility()) {
        return display_minion_triggered_ability(
            minion->getName(), minion->getCost(), attack, defense,
            minion->getTriggeredAbility()->getDescription());
    } else {
        return display_minion_no_ability(minion->getName(), minion->getCost(), attack, defense);
    }
}

void TextualDisplay::showBoard(const Game& game) {
    const size_t WIDTH = 5 * CARD_TEMPLATE_EMPTY.front().size(); // trust me bro

    // Build all inner lines (without outer top/bottom borders)
    std::vector<std::string> beforeGraphicinner;
    card_template_t mid = CENTRE_GRAPHIC;
    std::vector<std::string> afterGraphicinner;

    // ----- Player 1 header row (5 cards: empty, empty, P1, empty, empty)
    {
        auto p1 = game.getPlayer(1);
        auto empty = CARD_TEMPLATE_EMPTY;
        auto p1Card = display_player_card(1, p1->getName(), p1->getHealth(), p1->getMagic());
        auto ritual = CARD_TEMPLATE_BORDER;
        auto graveyard = CARD_TEMPLATE_BORDER;
        if (Ritual* ritualptr = dynamic_cast<Ritual*>(p1->getBoard()->getRitual()))
        {
            ritual = display_ritual(ritualptr->getName(), ritualptr->getCost(),
            ritualptr->getActivationCost(), ritualptr->getDescription(),
            ritualptr->getNumberOfCharges());
        }
        if (Minion* m = dynamic_cast<Minion*>(p1->getGraveyard()->getLastCardAdded()))
        {
            graveyard = display_minion(m);
        }
        std::vector<card_template_t> row{ritual, empty, p1Card, empty, graveyard};
        auto lines = flattenRow(row);
        beforeGraphicinner.insert(beforeGraphicinner.end(), lines.begin(), lines.end());
    }

    // ----- Player 1 minions
    {
        auto p1 = game.getPlayer(1);
        std::vector<card_template_t> row;
        auto& board = *p1->getBoard();
        for (int i = 0; i < board.getSize(); ++i) {
            Minion* m = static_cast<Minion*>(board.getCard(i));
            row.push_back(display_minion(m));
        }
        while (row.size() < 5) {
            row.push_back(CARD_TEMPLATE_BORDER);
        }

        auto lines = flattenRow(row);
        beforeGraphicinner.insert(beforeGraphicinner.end(), lines.begin(), lines.end());
    }


    // ----- Player 2 minions
    {
        auto p2 = game.getPlayer(2);
        std::vector<card_template_t> row;
        auto& board = *p2->getBoard();
        for (int i = 0; i < board.getSize(); ++i) {
            Minion* m = static_cast<Minion*>(board.getCard(i));
            row.push_back(display_minion(m));
        }
        while (row.size() < 5) {
            row.push_back(CARD_TEMPLATE_BORDER);
        }
        auto lines = flattenRow(row);
        afterGraphicinner.insert(afterGraphicinner.end(), lines.begin(), lines.end());
    }

    // ----- Player 2 footer row
    {
        auto p2 = game.getPlayer(2);
        auto empty = CARD_TEMPLATE_EMPTY;
        auto p2Card = display_player_card(2, p2->getName(), p2->getHealth(), p2->getMagic());
        auto ritual = CARD_TEMPLATE_BORDER;
        auto graveyard = CARD_TEMPLATE_BORDER;
        if (Ritual* ritualptr = dynamic_cast<Ritual*>(p2->getBoard()->getRitual()))
        {
            ritual = display_ritual(ritualptr->getName(), ritualptr->getCost(),
            ritualptr->getActivationCost(), ritualptr->getDescription(),
            ritualptr->getNumberOfCharges());
        }
        if (Minion* m = dynamic_cast<Minion*>(p2->getGraveyard()->getLastCardAdded()))
        {
            graveyard = display_minion(m);
        }
        std::vector<card_template_t> row{ritual, empty, p2Card, empty, graveyard};
        auto lines = flattenRow(row);
        afterGraphicinner.insert(afterGraphicinner.end(), lines.begin(), lines.end());
    }

    printTopBorder(WIDTH);

    for (auto& ln : beforeGraphicinner) {
        printLineWithBorders(ln, WIDTH);
    }

    for (auto& ln : mid) {
        std::cout << ln << "\n";
    }
    for (auto& ln : afterGraphicinner) {
        printLineWithBorders(ln, WIDTH);
    }

    printBottomBorder(WIDTH);
}
 
void TextualDisplay::showHand(const Hand& hand) {
    std::vector<card_template_t> cards;
    for (int i = 0; i < hand.getSize(); i++) {
        if (auto enchantment = dynamic_cast<const Enchantment*>(hand.getCard(i))) {
            auto enchantmentTemplate = displayEnchantment(enchantment);
            cards.push_back(enchantmentTemplate);
        }
        else if (auto minion = dynamic_cast<const Minion*>(hand.getCard(i))) {
            cards.push_back(display_minion(minion));
        } 
        else if (auto spell = dynamic_cast<const Spell*>(hand.getCard(i))) {
            auto card = display_spell(spell->getName(), spell->getCost(), spell->getDescription());
            cards.push_back(card);
        }
        else if (auto ritual = dynamic_cast<const Ritual*>(hand.getCard(i))) {
            auto card = display_ritual(
                ritual->getName(),
                ritual->getCost(),
                ritual->getActivationCost(),
                ritual->getDescription(),
                ritual->getNumberOfCharges());
            cards.push_back(card);
        }
        else {
            cout << "Card " << i + 1 << ": " << hand.getCard(i)->getName() << endl;
            cout << "Unprintable type in hand." << endl;
        }
    }
    displayTemplates(cards);
    if (hand.getSize() == 0) {
        cout << "No cards in hand" << endl;
    }
}

void TextualDisplay::invalidCommand() {
    cerr << "Invalid command" << endl;
}

card_template_t TextualDisplay::displayEnchantment(const Enchantment* enchantment) const {
    if (enchantment->getAttackModifier().empty() && enchantment->getDefenseModifier().empty()) {
        return display_enchantment(enchantment->getName(), enchantment->getCost(), enchantment->getDescription());
    } else {
        return display_enchantment_attack_defence(
            enchantment->getName(),
            enchantment->getCost(),
            enchantment->getDescription(),
            enchantment->getAttackModifier(),
            enchantment->getDefenseModifier());
    }
}

void TextualDisplay::showErrorMessage(const std::string& message) {
    cerr << "[Error] " << message << endl;
}

void TextualDisplay::showWinner(const std::string& winner) {
    card_template_t winnerTemplate = display_player_card(1, winner + " wins!!!", 100, 100);
    displayTemplate(winnerTemplate);
}
