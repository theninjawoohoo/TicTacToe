//Includes board.h and makes the definitions

#include "Board.h"
#include <iostream>
#include <vector>

using namespace std;

Board::Board() {
	//Construct board with default tiles.			
	for(int x = 0; x < BOARD_SIZE; x++) {
		boardTiles[x] = Tile::DEFAULT;
	}
}

void Board::printBoard() {
	
	string BORDER_TOP = "  +-------+";
	cout << BORDER_TOP << endl;
	
	for(int y = 0; y < 3; y++) {
		cout << y << " | ";
		for(int x = 0; x < 3; x++) {	
			cout << shortToTile(boardTiles[coordToBoardPosition(x, y)]) << " ";
		}
		cout << "|" << endl;
	}
	cout << BORDER_TOP << endl;
	cout << "    0 1 2" << endl;
}

char Board::shortToTile(short x) {
	char tile;
	switch(x) {
		case 0: tile = ' '; break;
		case 1: tile = 'X'; break;
		case 2: tile = 'O'; break;
	}
	return tile;
}

int Board::coordToBoardPosition(int x, int y) {
	return x + (3*y);
}

bool Board::inBounds(int x, int y) {
	return  x >= 0 && x <= 2 && y >= 0 && y <= 2;
}

bool Board::unoccupied(int x, int y) {
	return boardTiles[coordToBoardPosition(x, y)] == Tile::DEFAULT;
}

bool Board::checkForWinner() {
	return checkRows() || checkColumns() || checkDiagonals();
}

bool Board::checkRows() {
	for (int i = 0; i < 3; i++) {
		short left = boardTiles[3*i];
		short mid = boardTiles[3*i + 1];
		short right = boardTiles[3*i + 2];
		if (left == mid && left == right && left != Tile::DEFAULT) {
			return true;
		}
	}
	return false;
}	

bool Board::checkColumns() {
	for (int i = 0; i < BOARD_SIZE; i++) {
		short top = boardTiles[i];
		short mid = boardTiles[i + 3];
		short bot = boardTiles[i + 6];
		if (top == mid && top == bot && top != Tile::DEFAULT) {
			return true;
		}
	}
	return false;
}

bool Board::checkDiagonals() {
	char topLeft = boardTiles[0];
	char topRight = boardTiles[2];
	char mid = boardTiles[4];
	char botLeft = boardTiles[6];
	char botRight = boardTiles[8];

	//Checks diagonal top left to bottom right
	if (topLeft == mid && botRight == mid && mid != Tile::DEFAULT) {
		return true;
	}
	//Checks diagonal top right to bottom left
	if (topRight == mid && botLeft == mid && mid!= Tile::DEFAULT) {
		return true;
	}

	return false;
}

vector<int> Board::possibleMoves() {
	vector<int> moves;
	for (unsigned int i = 0; i < BOARD_SIZE; i++) {
		if (boardTiles[i] == Tile::DEFAULT) {
			moves.push_back(i);
		}
	}
	return moves;
}

//Places tile on given board coordinates.
void Board::placeMove(int x, int y, short tile) {
	boardTiles[coordToBoardPosition(x, y)] = tile;
}

//Places tile on given board index.
void Board::placeMove(int i, short tile) {
	boardTiles[i] = tile;
}

bool Board::validInputPrint(int x, int y) {
	if (!inBounds(x, y)) {
		cout << "Location is out of bounds.\n" << endl;
		return false;
	}
	if (!unoccupied(x, y)) {
		cout << "Location is already occupied.\n" << endl;
		return false;
	}
	return true;
}

bool Board::validInput(int x, int y) {
	return inBounds(x, y) && unoccupied(x, y);
}