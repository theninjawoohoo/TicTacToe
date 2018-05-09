//This is the board class

//Guards
#ifndef BOARD_H
#define BOARD_H

using namespace std;

class Board {
private:
	static const int OLD_BOARD_SIZE = 3;
	static const int BOARD_SIZE = 9;
	short boardTiles[BOARD_SIZE];
	bool inBounds(int x, int y);
	bool unoccupied(int x, int y);

public:
	Board();

	enum Tile:short {DEFAULT = 1, X = 2, O = 0};

	void printBoard();
	bool checkForWinner();
	bool checkRows();
	bool checkColumns();
	bool checkDiagonals();

	void placeMove(int x, int y, short tile);
	bool validInputPrint(int x, int y);
	bool validInput(int x, int y);
	
};

#endif //Board.h
