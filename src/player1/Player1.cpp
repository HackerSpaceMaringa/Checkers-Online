#include "Player1.h"

void Player1::answerPlayer(){
    if (player == WHITE)
        Communication::sendMessage(socket, newId, oldId);
}

void Player1::communicationType(){
    Communication::initCommunication(&socket);
}

void Player1::waitPlayer(){
    if (player == BLACK){
        Communication::readMessage(socket, &newId, &oldId);
        gameControl->setValidPositions(oldId);
    }
}
