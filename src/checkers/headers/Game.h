#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include "Board.h"
#include "Checkerboard.h"
#include "EventHandler.h"
#include "MainMenu.h"
#include "defines.h"
#include "Communication.h"


class Game: public EventHandler{
    protected:
        int player;
        bool sameTurn;
        int winner;
        bool done;
        int oldId, newId;
        SDL_Surface* displayVideo;
        void renderGame();
        Board* gameControl;
        MainMenu gameMenu;
        tcp::socket *socket;

    public:
        Game();
        bool initGame();
        bool startGame();
        void resetGame();
        void executeGame();
        void endGame();
        void checkGameSituation();
        void quitGame();
        void keyPressedDown(SDLKey key);
        void mouseLeftPressedDown(int x, int y);
        virtual void waitPlayer(){}
        virtual void communicationType(){}
        virtual void answerPlayer(){}
};

#endif
