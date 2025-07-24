#include "textualdisplay.h"
#include "enchantment.h"
#include "spell.h"
#include "minion.h"
#include <iostream>
#include "ascii_graphics.h"

using namespace std;

void TextualDisplay::displayTemplate(const card_template_t& templateLines) const {
    int lineNumber = 0;
    for (const auto& line : templateLines) {
        cout << line;
        if (lineNumber < templateLines.size() - 1) {
            cout << endl;
        }
        lineNumber++;
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
        auto card = display_minion_no_ability(minion.getName(), minion.getCost(), minion.getAttack(), minion.getDefense());
        displayTemplate(card);
        return;
    }
    vector<card_template_t> enchantmentLines;
    const Minion* nextMinion = current->getNext();
    while (current) {

        // create current enchantment template and then display it
        card_template_t enchantmentTemplate = displaEnchantment(current);
        enchantmentLines.push_back(enchantmentTemplate);
        // move to the next enchantment
        nextMinion =  current->getNext();
        current = dynamic_cast<const Enchantment*>(nextMinion);
        
    }

    // print nextMinion
    auto card = display_minion_no_ability(nextMinion->getName(), nextMinion->getCost(), nextMinion->getAttack(), nextMinion->getDefense());
    displayTemplate(card);
    cout << endl;
    // print all enchantments in reverse order
    int printedEnchantments = 0;
    for (auto it = enchantmentLines.rbegin(); it != enchantmentLines.rend(); ++it) {
        displayTemplate(*it);
        printedEnchantments++;
        if (printedEnchantments > 0 && printedEnchantments % 5 == 0) {
            cout << endl;
        }
    }

}

void TextualDisplay::showBoard(const Game& game) {
    cout << "--------------------------------" << endl;
    cout << game.getActivePlayer()->getName() << "'s Health: " << game.getActivePlayer()->getHealth() << endl;
    cout << game.getActivePlayer()->getName() << "'s Magic: " << game.getActivePlayer()->getMagic() << endl;
    cout << game.getActivePlayer()->getName() << "'s Cards: " << endl;
    for (int i = 0; i < game.getActivePlayer()->getBoard()->getSize(); i++) {
        cout << "Card " << i + 1 << ": " << game.getActivePlayer()->getBoard()->getCard(i)->getName() << endl;
    }
    if (game.getActivePlayer()->getBoard()->getSize() == 0) {
        cout << "No cards on the board" << endl;
    }
    cout << game.getActivePlayer()->getName() << "'s Graveyard: " << endl;
    for (int i = 0; i < game.getActivePlayer()->getGraveyard()->getSize(); i++) {
        cout << "Card " << i + 1 << ": " << game.getActivePlayer()->getGraveyard()->getCard(i)->getName() << endl;
    }
    if (game.getActivePlayer()->getGraveyard()->getSize() == 0) {
        cout << "No cards in graveyard" << endl;
    }
    cout << "--------------------------------" << endl;
    cout << game.getInactivePlayer()->getName() << "'s Health: " << game.getInactivePlayer()->getHealth() << endl;
    cout << game.getInactivePlayer()->getName() << "'s Magic: " << game.getInactivePlayer()->getMagic() << endl;
    cout << game.getInactivePlayer()->getName() << "'s Cards: " << endl;
    for (int i = 0; i < game.getInactivePlayer()->getBoard()->getSize(); i++) {
        cout << "Card " << i + 1 << ": " << game.getInactivePlayer()->getBoard()->getCard(i)->getName() << endl;
    }
    if (game.getInactivePlayer()->getBoard()->getSize() == 0) {
        cout << "No cards on the board" << endl;
    }
    cout << game.getInactivePlayer()->getName() << "'s Graveyard: " << endl;
    for (int i = 0; i < game.getInactivePlayer()->getGraveyard()->getSize(); i++) {
        cout << "Card " << i + 1 << ": " << game.getInactivePlayer()->getGraveyard()->getCard(i)->getName() << endl;
    }
    if (game.getInactivePlayer()->getGraveyard()->getSize() == 0) {
        cout << "No cards in graveyard" << endl;
    }
    cout << "--------------------------------" << endl;
}
 
void TextualDisplay::showHand(const Hand& hand) {
    int printedCards = 0;
    for (int i = 0; i < hand.getSize(); i++) {
        if (auto minion = dynamic_cast<const Minion*>(hand.getCard(i))) {
            auto card = display_minion_no_ability(minion->getName(), minion->getCost(), minion->getAttack(), minion->getDefense());
            displayTemplate(card);
        } else if (auto enchantment = dynamic_cast<const Enchantment*>(hand.getCard(i))) {
            auto enchantmentTemplate = displaEnchantment(enchantment);
            displayTemplate(enchantmentTemplate);
        }
        else if (auto spell = dynamic_cast<const Spell*>(hand.getCard(i))) {
            auto card = display_spell(spell->getName(), spell->getCost(), spell->getDescription());
            displayTemplate(card);
        } 
        else {
            cout << "Unprintable type in hand." << endl;
        }
        printedCards++;

        if (printedCards > 0 && printedCards % 5 == 0) {
            cout << endl;
        }
    }
    if (hand.getSize() == 0) {
        cout << "No cards in hand" << endl;
    }
}

void TextualDisplay::invalidCommand() {
    cerr << "Invalid command" << endl;
}

card_template_t TextualDisplay::displaEnchantment(const Enchantment* enchantment) const {
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
