#include "Player2.h"

void Player2::answerPlayer(){
    if (player == BLACK)
        Communication::sendMessage(socket, newId, oldId);
}

void Player2::communicationType(){
    Communication::waitCommunication(&socket);
}

void Player2::waitPlayer(){
    if (player == WHITE){
        Communication::readMessage(socket, &newId, &oldId);
        gameControl->setValidPositions(oldId);
    }
}

bool Player2::isWaiting(int player){
    if (player == WHITE) return true;
    return false;
}
