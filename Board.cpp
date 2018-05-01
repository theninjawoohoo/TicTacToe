//Includes board.h and makes the definitions

#include "Board.h"
#include <iostream>

using namespace std;

Board::Board() {
	//Construct board with default tiles.			
	for(int x = 0; x < BOARD_SIZE; x++) {
		for(int y = 0; y < BOARD_SIZE; y++) {
			boardTiles[y][x] = Tile::DEFAULT;
		}
	}
}


void Board::printBoard() {
	string BORDER_TOP = "  +-------+";
	cout << "    0 1 2" << endl;
	cout << BORDER_TOP << endl;
	for(int y = 0; y < BOARD_SIZE; y++) {
		cout << y << " | ";
		for(int x = 0; x < BOARD_SIZE; x++) {	
			cout << boardTiles[y][x] << " ";
		}
		cout << "|" << endl;
	}
	cout << BORDER_TOP << endl;
}

bool Board::checkForWinner() {
	return checkRows() || checkColumns() || checkDiagonals();
}

bool Board::checkRows() {
	for (int y = 0; y < BOARD_SIZE; y++) {
		char left = boardTiles[y][0];
		char mid = boardTiles[y][1];
		char right = boardTiles[y][2];
		if (left == mid && left == right && left != Tile::DEFAULT)
			return true;
	}
	return false;
}	

bool Board::checkColumns() {
	for (int x = 0; x < BOARD_SIZE; x++) {
		char top = boardTiles[0][x];
		char mid = boardTiles[1][x];
		char bot = boardTiles[2][x];
		if (top == mid && top == bot && top != Tile::DEFAULT)
			return true;
	}
	return false;
}

bool Board::checkDiagonals() {
	char topLeft = boardTiles[0][0];
	char topRight = boardTiles[0][2];
	char mid = boardTiles[1][1];
	char botLeft = boardTiles[2][0];
	char botRight = boardTiles[2][2];

	//Checks diagonal top left to bottom right
	if (topLeft == mid && botRight == mid && mid != Tile::DEFAULT)
		return true;
	//Checks diagonal top right to bottom left
	if (topRight == mid && botLeft == mid && mid!= Tile::DEFAULT)
		return true;

	return false;
}

bool Board::inBounds(int x, int y) {
	return x < BOARD_SIZE && x >= 0 && y < BOARD_SIZE && y >= 0;
}

bool Board::unoccupied(int x, int y) {
	return boardTiles[y][x] == Tile::DEFAULT;
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

void Board::placeMove(int x, int y, char tile) {
	boardTiles[y][x] = tile;
}