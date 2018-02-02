//This is the board class

#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "cmpt_error.h"

class Board {
private:
	const int maxSize = 2;
	char boardTiles[maxSize][maxSize];	

public:
	Board();
	
	int getMaxSize();
	void printBoard();
	void checkForWinner();
	bool checkIfValidInput();
	void placeMove();
};

#endif