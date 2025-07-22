#include "gamecontroller.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "attackcommand.h"
#include "playcommand.h"
#include "minion.h"

using namespace std;

// constructor
GameController::GameController() {
}

// play game

void GameController::playGame(const string& initFile, const string& deck1File, const string& deck2File) {
    string name1;
    string name2;
    
    // if init file is provided, load it
    if (!initFile.empty()) {
        ifstream file(initFile);
        // check if file is opened
        if (!file.is_open()) {
            cerr << "Error: Could not open file " << initFile << endl;
            return;
        }

        // read player names
        getline(file, name1);
        getline(file, name2);

        game = make_unique<Game>(name1, name2, deck1File, deck2File);

        start();
        
        // read file line by line
        string line;
        while (getline(file, line)) {
            if (!line.empty()) {
                // process command
                processCommand(line);
                if (line == "quit") {
                    return;
                }
            }
        } 
        
        // close file
        file.close();
    } else {
        getline(cin, name1);
        getline(cin, name2);
        game = make_unique<Game>(name1, name2, deck1File, deck2File);
        start();
    }

    string command;

    // main loop, take additional commands
    while (true) {
        std::cout << "Enter command: ";
        getline(cin, command);
        
        // process command
        processCommand(command);
        if (command == "quit") {
            return;
        }
    }
}

void GameController::processCommand(const string& command) {
    // split command into tokens
    istringstream iss(command);
    string cmd;
    iss >> cmd;


    if (cmd == "help") {
        help();
    } else if (cmd == "end") {
        end();
    } else if (cmd == "quit") {
        quit();
    } else if (cmd == "draw") {
        draw();
    } else if (cmd == "discard") {
        string args;
        getline(iss, args);
        discard(args);
    } else if (cmd == "attack") {
        string args;
        getline(iss, args);
        attack(args);
    } else if (cmd == "play") {
        string args;
        getline(iss, args);
        play(args);
    } else if (cmd == "use") {
        string args;
        getline(iss, args);
        use(args);
    } else if (cmd == "describe") {
        string args;
        getline(iss, args);
        describe(args);
    } else if (cmd == "hand") {
        hand();
    } else if (cmd == "board") {
        board();
    } else {
        cout << "Invalid command" << endl;
    }
}

void GameController::help() {
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

void GameController::end() {
    game->endTurn();
    game->startTurn();
}

void GameController::start() {
    game->startTurn();
}

void GameController::quit() {
    cout << "Quitting game" << endl;
}

void GameController::draw() {
    cout << "draw" << endl;
}

void GameController::discard(const string& args) {
    cout << "discard" << args << endl;
}

void GameController::attack(const string& args) {
    istringstream iss(args);
    int i;
    int j;
    iss >> i;
    if (iss >> j) {
        game->notify(make_unique<AttackCommand>(i - 1, j - 1));
    } else {
        game->notify(make_unique<AttackCommand>(i - 1));
    }
}

void GameController::play(const string& args) {
    istringstream iss(args);
    int i;
    int p;
    int t;
    char target_card;
    iss >> i;
    if (iss >> p && iss >> target_card) {
        if (target_card == 'r') {
            t = 0;
        } else {
            t = target_card - '0';
        }
        game->notify(make_unique<PlayCommand>(i - 1, p - 1, t));
    } else {
        game->notify(make_unique<PlayCommand>(i - 1));
    }
}

void GameController::use(const string& args) {
    cout << "use" << args << endl;
}

void GameController::describe(const string& args) {
    istringstream iss(args);
    int i;
    iss >> i;
    if (i > 0 and i <= game->getActivePlayer()->getBoard()->getSize()) {
        Minion* minion = dynamic_cast<Minion*>(game->getActivePlayer()->getBoard()->getCard(i - 1));
        if (minion) {
            cout << "Minion " << i << ": " << minion->getName() << endl;
            cout << "Description: " << minion->getDescription() << endl;
            cout << "Cost: " << minion->getCost() << endl;
            cout << "Attack: " << minion->getAttack() << endl;
            cout << "Defense: " << minion->getDefense() << endl;
            cout << "Actions: " << minion->getActions() << endl;
        } else {
            cout << "Invalid minion" << endl;
        }
    } else {
        cout << "Invalid index" << endl;
    }
}

void GameController::hand() {
    cout << game->getActivePlayer()->getName() << "'s Hand: " << endl;
    if (game->getActivePlayer()->getHand()->getSize() > 0) {
        for (int i = 0; i < game->getActivePlayer()->getHand()->getSize(); i++) {
            cout << "Card " << i + 1 << ": " << game->getActivePlayer()->getHand()->getCard(i)->getName() << endl;
        }
    } else {
        cout << "No cards in hand" << endl;
    }
}

void GameController::board() {
    cout << game->getActivePlayer()->getName() << "'s Board: " << endl;
    if (game->getActivePlayer()->getBoard()->getSize() > 0) {
        for (int i = 0; i < game->getActivePlayer()->getBoard()->getSize(); i++) {
            cout << "Card " << i + 1 << ": " << game->getActivePlayer()->getBoard()->getCard(i)->getName() << endl;
        }
    } else {
        cout << "No cards on the board" << endl;
    }
}
