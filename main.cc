#include <iostream>
#include <string>
#include <fstream>
#include "gamecontroller.h"

using namespace std;

struct gameArgs {
    string initFile = "";
    string deck1File = "default.deck";
    string deck2File = "default.deck";
    bool test = false;
};

int main(int argc, char* argv[]) {
    // check if init flag is set in command line arguments
    gameArgs args;

    for (int i  = 1; i < argc; i++) {
        string arg = argv[i];
        if (arg == "-init") {
            if (i + 1 < argc) {
                args.initFile = argv[i + 1];
                i++;
            }
        } else if (arg == "-deck1") {
            if (i + 1 < argc) {
                args.deck1File = argv[i + 1];
                i++;
            }
        } else if (arg == "-deck2") {
            if (i + 1 < argc) {
                args.deck2File = argv[i + 1];
                i++;
            }
        } else if (arg == "-testing") {
            args.test = true;
        }
    }

    // initialize game controller
    GameController controller;

    controller.playGame(args.initFile, args.deck1File, args.deck2File, args.test);
}
