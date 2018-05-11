//This is the board class

//Guards
#ifndef BOARD_H
#define BOARD_H

using namespace std;

class Board {
private:
	static const int BOARD_SIZE = 9;
	short boardTiles[BOARD_SIZE];
	int coordToBoardPosition(int x, int y);
	char shortToTile(short x);
	bool inBounds(int x, int y);
	bool unoccupied(int x, int y);

public:
	Board();

	enum Tile:short {DEFAULT = 0, X = 1, O = 2};

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
