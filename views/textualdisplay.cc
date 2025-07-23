#include "textualdisplay.h"

#include <iostream>

using namespace std;

void TextualDisplay::help() {
    cout << "Commands:" << endl;
    cout << "help -- Display this message" << endl;
    cout << "end -- End this current player's turn" << endl;
    cout << "quit -- End the game" << endl;
    cout << "attack minion other-minion -- Orders minion to attack other-minion" << endl;
    cout << "attack minion -- Orders minion to attack the opponent" << endl;
    cout << "play card [target-player target-card] -- Play card, optionally targeting target-card owned by target-player" << endl;
    cout << "use minion [target-player target-card] -- Use minion's special ability, optionally targeting target-card owned by target-player" << endl;
    cout << "inspect minion -- View a minion's card and all enchantments on that minion" << endl;
    cout << "hand -- Describe all cards in your hand" << endl;
    cout << "board -- Describe all cards on the board" << endl;
}

void TextualDisplay::inspect(const Minion& minion) {
    cout << "Minion: " << minion.getName() << endl;
    cout << "Description: " << minion.getDescription() << endl;
    cout << "Cost: " << minion.getCost() << endl;
    cout << "Attack: " << minion.getAttack() << endl;
    cout << "Defense: " << minion.getDefense() << endl;
    cout << "Actions: " << minion.getActions() << endl;
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
    for (int i = 0; i < hand.getSize(); i++) {
        cout << "Card " << i + 1 << ": " << hand.getCard(i)->getName() << endl;
    }
    if (hand.getSize() == 0) {
        cout << "No cards in hand" << endl;
    }
}

void TextualDisplay::invalidCommand() {
    cerr << "Invalid command" << endl;
}
