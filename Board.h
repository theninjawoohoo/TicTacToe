//This is the board class

//Guards
#ifndef BOARD_H
#define BOARD_H

#include <vector>

using namespace std;

class Board {
private:
	static const int BOARD_SIZE = 9;
	short boardTiles[BOARD_SIZE];
	char shortToTile(short x);
	int coordToBoardPosition(int x, int y);
	bool inBounds(int x, int y);
	bool unoccupied(int x, int y);

	bool checkRows();
	bool checkColumns();
	bool checkDiagonals();

public:
	Board();

	enum Tile:short {DEFAULT = 0, X = 1, O = 2};

	void printBoard();
	bool checkForWinner();

	vector<int> possibleMoves(); 
	void placeMove(int x, int y, short tile);
	void placeMove(int i, short tile);

	bool validInputPrint(int x, int y);
	bool validInput(int x, int y);
};

#endif //Board.h
