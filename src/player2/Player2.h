#ifndef PLAYER2_H
#define PLAYER2_H

#include "Game.h"

class Player2: public Game{
    public:
        void waitPlayer();
        void communicationType(char*);
        void answerPlayer();
        bool isWaiting(int);
};

#endif
