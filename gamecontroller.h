#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <string>
#include "enums.h"
#include "game.h"

using namespace std;

class GameController {
    // pointers to game and view objects
    unique_ptr<Game> game;
    unique_ptr<View> view;
    
    public:
        GameController();
        ~GameController();
    
        void playGame(const string& initFile, const string& deck1File, const string& deck2File);
    
    private:
        void processCommand(const string& command);
        void help();
        void end();
        void start();
        void quit();
        void draw();
        void discard(const string& args);
        void attack(const string& args);
        void play(const string& args);
        void use(const string& args);
        void describe(const string& args);
        void hand();
        void board();
};

#endif