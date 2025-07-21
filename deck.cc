#include "deck.h"
#include <fstream>

using namespace std;

Deck::Deck(const string& deckFile) {
    cards.clear();
    
    ifstream file(deckFile);
    string line;
    while (getline(file, line)) {
        if (!line.empty()) {
            cards.push_back(line);
        }
    }
    
    file.close();

    // cout << "Deck: ";

    // for (const string& card : cards) {
    //     cout << card << " ";
    // }
    
    // cout << endl;
}
