#include "gamecontroller.h"
#include <iostream>
#include <fstream>
#include <sstream>

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
    cout << "help" << endl;
}

void GameController::end() {
    cout << "End of turn " << game->getActivePlayer()->getName() << endl;
    game->endTurn();
    cout << "Start of turn " << game->getActivePlayer()->getName() << endl;
    game->startTurn();
}

void GameController::quit() {}

void GameController::draw() {
    cout << "draw" << endl;
}

void GameController::discard(const string& args) {
    cout << "discard" << args << endl;
}

void GameController::attack(const string& args) {
    cout << "attack" << args << endl;
}

void GameController::play(const string& args) {
    cout << "play" << args << endl;
}

void GameController::use(const string& args) {
    cout << "use" << args << endl;
}

void GameController::describe(const string& args) {
    cout << "describe" << args << endl;
}

void GameController::hand() {
    cout << "hand" << endl;
}

void GameController::board() {
    cout << "board" << endl;
}
