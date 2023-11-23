#ifndef __GAMECONTROLLER_H__
#define __GAMECONTROLLER_H__
#include "gamemaster.h"
#include "textdisplay.h"

class GameController {
    GameMaster gm; 
    TextDisplay td;
    // GraphicsDisplay gd;

    /*private helper functions here */
    // helper function to find command line variables
    bool findIndex(int argc, char* argv[], string s, int& i);

    void testCmdArg(string arg, string filename = "n/a");

    public:
        GameController();
        ~GameController();
        
        void go(int argc, char *argv[]);
};


#endif