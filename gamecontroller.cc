#include "gamecontroller.h"
#include "view.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "textualdisplay.h"
#include "attackcommand.h"
#include "playcommand.h"
#include "minion.h"

using namespace std;

// constructor
GameController::GameController() {
    view = make_unique<TextualDisplay>();
}

GameController::~GameController() = default;

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
        view->invalidCommand();
    }
}

void GameController::help() {
    view->help();
}

void GameController::end() {
    game->endTurn();
    game->startTurn();
}

void GameController::start() {
    game->startTurn();
}

void GameController::quit() {
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

    if (i < 1 || i > game->getActivePlayer()->getBoard()->getSize()) {
        view->invalidCommand();
        return;
    }

    if (iss >> j) {
        if (j < 1 || j > game->getInactivePlayer()->getBoard()->getSize()) {
            view->invalidCommand();
            return;
        }
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

    if (i < 1 || i > game->getActivePlayer()->getHand()->getSize()) {
        view->invalidCommand();
        return;
    }

    if (iss >> p && iss >> target_card) {
        if (target_card == 'r') {
            t = 0;
        } else {
            t = target_card - '0';
        }

        if (p < 1 || p > 2 || t < 0 || t > game->getPlayer(p)->getBoard()->getSize()) {
            view->invalidCommand();
            return;
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
            view->inspect(*minion);
        }
    } else {
        view->invalidCommand();
    }
}

void GameController::hand() {
    view->showHand(*game->getActivePlayer()->getHand());
}
    

void GameController::board() {
    view->showBoard(*game);
}
