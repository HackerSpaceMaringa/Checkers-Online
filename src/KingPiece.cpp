#include "headers/KingPiece.h"

KingPiece::KingPiece(int color){
	this->color = color;
	type = KING;
}

map<int,int> KingPiece::positionValues(int id, std::vector<Piece*> board){
	map<int,int> values;
	int diagonal = (int)sqrt(BOARD_SIZE) - 1;
	int diagId;

	for (int i = 0; i < 2; i++){

		if (id % (int)sqrt(BOARD_SIZE) == 0){
			decrementDiagonal(diagId,id,diagonal,&values,board);
			diagonal += 2;
			incrementDiagonal(diagId,id,diagonal,&values,board);
			break;
		}

		else if (id % (int)sqrt(BOARD_SIZE) == (int)sqrt(BOARD_SIZE) - 1){
			incrementDiagonal(diagId,id,diagonal,&values,board);
			diagonal += 2;
			decrementDiagonal(diagId,id,diagonal,&values,board);
			break;
		}
		else{
			decrementDiagonal(diagId,id,diagonal,&values,board);
			incrementDiagonal(diagId,id,diagonal,&values,board);
			diagonal += 2;
		}
	}
	removeUnkilledPositions(&values);
	return values;
}

void KingPiece::selectTarget(int diagId, int diagonal, map<int,int>* values,
		vector<Piece*> board){
	if (this->color != board[diagId]->color && 
			board[diagId - diagonal] == NULL){
		values->insert(pair<int,int>(diagId - diagonal,diagId));
		canKill = true;
	}
	else if (this->color != board[diagId]->color &&
			board[diagId + diagonal] == NULL){
		values->insert(pair<int,int>(diagId + diagonal,diagId));
		canKill = true;
	}

}
