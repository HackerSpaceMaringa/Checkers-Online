#ifndef PLAYER1_H
#define PLAYER1_H

#include "Game.h"

class Player1: public Game{
    public:
        void waitPlayer();
        void communicationType(char *address);
        void answerPlayer();
        bool isWaiting(int);
};

#endif
