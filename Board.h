//This is the board class

//Guards
#ifndef BOARD_H
#define BOARD_H

#include <iostream>

using namespace std;

class Board {
private:
	static const int MAX_SIZE = 3;
	char boardTiles[MAX_SIZE][MAX_SIZE];
	enum Tile:char {DEFAULT = '_', X = 'X',	O = 'O'};

	bool validInput(int x, int y);

public:
	Board();

	void printBoard();
	void checkForWinner();
	//Coordinates will be generated
	bool placeMove(int x, int y, char tile);
};

#endif //Board.h
