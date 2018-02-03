//This is the board class

//Guards
#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "cmpt_error.h"

using namespace std;

class Board {
private:
	static const int MAX_SIZE = 2;
	char boardTiles[MAX_SIZE][MAX_SIZE];	

public:
	Board();


	void printBoard();
	void checkForWinner();
	bool checkIfValidInput();
	//Coordinates will be generated
	void placeMove(string coordinates);


};

#endif //Board.h
