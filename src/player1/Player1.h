#ifndef PLAYER1_H
#define PLAYER1_H

#include "Game.h"
#include "Communication.h"

class Player1: public Game{
    public:
        void waitPlayer();
        void communicationType();
        void answerPlayer();
};

#endif
