#include "gamecontroller.h"
#include "view.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "textualdisplay.h"
#include "attackcommand.h"
#include "playcommand.h"
#include "usecommand.h"
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
                processCommand(line, testFlag);
                if (line == "quit") {
                    return;
                }
                if (checkGameOver()) {
                    break; // exit if game is over
                }
            }
        } 
        
        // close file
        file.close();
    } else {
        getline(cin, name1);
        getline(cin, name2);
        game = make_unique<Game>(name1, name2, deck1File, deck2File);
        if (!testFlag) {
            game->getActivePlayer()->getDeck()->shuffle();
            game->getInactivePlayer()->getDeck()->shuffle();
        }
        start();
    }

    string command;

    // main loop, take additional commands
    while (true) {

        if (checkGameOver()) {
            break; // exit if game is over
        }
        getline(cin, command);
        // process command
        processCommand(command, testFlag);
        if (command == "quit") {
            return;
        }
    }
}

bool GameController::checkGameOver() {
    if (game->getActivePlayer()->getHealth() <= 0) {
        view->showWinner(game->getInactivePlayer()->getName());
        return true;
    } else if (game->getInactivePlayer()->getHealth() <= 0) {
        view->showWinner(game->getActivePlayer()->getName());
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
            view->showErrorMessage("Cannot play card: " + string(e.what()));
        }
    } else if (cmd == "use") {
        string args;
        getline(iss, args);
        try {
            use(args);
        } catch (const std::exception& e) {
            view->showErrorMessage("Cannot use minion: " + string(e.what()));
        }
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
    if (!iss)
    {
        view->invalidCommand();
        return;
    }
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
    if (!iss)
    {
        view->invalidCommand();
        return;
    }

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
    string target_card;
    iss >> i;
    if (!iss)
    {
        view->invalidCommand();
        return;
    }

    if (i < 1 || i > game->getActivePlayer()->getHand()->getSize()) {
        view->invalidCommand();
        return;
    }

    if (iss >> p && iss >> target_card) {
        if (p < 1 || p > 2) {
            view->showErrorMessage( "Invalid player index. Use 1 or 2.");
            return;
        }
        if (target_card.empty() || target_card.size() != 1) {
            view->showErrorMessage("Invalid target card. Use a single character.");
            return;
        }
        char target_card_c = target_card[0];
        if (target_card_c == 'r') {
            t = -1; // ritual
        } else if (target_card_c >= '0' && target_card_c <= '4') {
            t = (target_card_c - '0') - 1; // convert char to int
        } else {

            view->showErrorMessage("Invalid target card. Use 'r' for ritual or a digit for minion index.");
            return;
        }
        if (p < 1 || p > 2 || t >= game->getPlayer(p)->getBoard()->getSize()) {
            view->invalidCommand();
            return;
        }
        
        game->notify(make_unique<PlayCommand>(i - 1, p, t));
    } else {
        game->notify(make_unique<PlayCommand>(i - 1));
    }
}

void GameController::use(const string& args) {
    istringstream iss(args);
    int i;
    int p;
    int t;
    string target_card;
    iss >> i;
    if (!iss)
    {
        view->invalidCommand();
        return;
    }

    if (i < 1 || i > game->getActivePlayer()->getBoard()->getSize()) {
        view->invalidCommand();
        return;
    }

    if (iss >> p && iss >> target_card) {
        if (p < 1 || p > 2) {
            view->showErrorMessage("Invalid player index. Use 1 or 2.");
            return;
        }
        if (target_card.empty() || target_card.size() != 1) {
            view->showErrorMessage("Invalid target card. Use a single character.");
            return;
        }
        char target_card_c = target_card[0];
        if (target_card_c == 'r') {
            t = -1; // ritual
        } else if (target_card_c >= '0' && target_card_c <= '4') {
            t = (target_card_c - '0') - 1; // convert char to int
        } else {
            view->showErrorMessage("Invalid target card. Use 'r' for ritual or a digit for minion index.");
            return;
        }
        if (p < 1 || p > 2 || t >= game->getPlayer(p)->getBoard()->getSize()) {
            view->invalidCommand();
            return;
        }
        
        game->notify(make_unique<UseCommand>(i - 1, p, t));
    } else {
        game->notify(make_unique<UseCommand>(i - 1));
    }
}

void GameController::describe(const string& args) {
    istringstream iss(args);
    int i;
    iss >> i;
    if (!iss)
    {
        view->invalidCommand();
        return;
    }
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
