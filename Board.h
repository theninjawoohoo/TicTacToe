//This is the board class

//Guards
#ifndef BOARD_H
#define BOARD_H

using namespace std;

class Board {
private:
	static const int BOARD_SIZE = 3;
	char boardTiles[BOARD_SIZE][BOARD_SIZE];
	bool inBounds(int x, int y);
	bool unoccupied(int x, int y);

public:
	Board();

	enum Tile:char {DEFAULT = '_', X = 'X',	O = 'O'};

	void printBoard();
	bool checkForWinner();
	bool checkRows();
	bool checkColumns();
	bool checkDiagonals();

	void placeMove(int x, int y, char tile);
	bool validInput(int x, int y);
};

#endif //Board.h
