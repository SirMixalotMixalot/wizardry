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

void GameController::playGame(const string& initFile, const string& deck1File, const string& deck2File, bool testFlag) {
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

        if (!testFlag) {
            game->getActivePlayer()->getDeck()->shuffle();
            game->getInactivePlayer()->getDeck()->shuffle();
        }

        start();
        
        // read file line by line
        string line;
        while (getline(file, line)) {
            if (!line.empty()) {
                // process command
                if (checkGameOver()) {
                    break; // exit if game is over
                }
                processCommand(line, testFlag);
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
        if (checkGameOver()) {
            break; // exit if game is over
        }
        // process command
        processCommand(command, testFlag);
        if (command == "quit") {
            return;
        }
    }
}

bool GameController::checkGameOver() {
    if (game->getActivePlayer()->getHealth() <= 0) {
        cout << game->getInactivePlayer()->getName() << " wins!" << endl;
        return true;
    } else if (game->getInactivePlayer()->getHealth() <= 0) {
        cout << game->getActivePlayer()->getName() << " wins!" << endl;
        return true;
    }

    return false;
}

void GameController::processCommand(const string& command, bool testFlag) {
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
        if (testFlag) {
            draw();
        } else {
            view->invalidCommand();
        }
    } else if (cmd == "discard") {
        string args;
        getline(iss, args);
        if (testFlag) {
            discard(args);
        } else {
            view->invalidCommand();
        }
    } else if (cmd == "attack") {
        string args;
        getline(iss, args);
        attack(args);
    } else if (cmd == "play") {
        string args;
        getline(iss, args);
        try {
            play(args);
        } catch (const std::exception& e) {
            cout << "Cannot play card: " << e.what() << endl;
        }
    } else if (cmd == "use") {
        string args;
        getline(iss, args);
        use(args);
    } else if (cmd == "inspect") {
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
    game->draw();
}

void GameController::discard(const string& args) {
    istringstream iss(args);
    int i;
    iss >> i;
    if (i < 1 || i > game->getActivePlayer()->getHand()->getSize()) {
        view->invalidCommand();
        return;
    }

    game->discard(i - 1);
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
        if (p < 1 || p > 2) {
            cout << "Invalid player index. Use 1 or 2." << endl;
            return;
        }
        if (target_card == 'r') {
            t = -1; // ritual
        } else if (target_card >= '0' && target_card <= '4') {
            t = (target_card - '0') - 1; // convert char to int
        } else {
            cout << "Invalid target card. Use 'r' for ritual or a digit for minion index." << endl;
            return;
        }
        if (p < 1 || p > 2 || t > game->getPlayer(p)->getBoard()->getSize()) {
            view->invalidCommand();
            return;
        }
        
        game->notify(make_unique<PlayCommand>(i - 1, p, t));
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
    if (i > 0 && i <= game->getActivePlayer()->getBoard()->getSize()) {
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
