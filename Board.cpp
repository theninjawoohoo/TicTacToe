//Includes board.h and makes the definitions

#include "Board.h"

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

bool Board::validInput(int x, int y) {
	//Checks if out of bounds
	if (x < 0 || x > BOARD_SIZE - 1 || y < 0 || y > BOARD_SIZE - 1) {
		cout << "Location is out of bounds.\n" << endl;
		return false;
	} 
	//Checks if location is occupied
	if (boardTiles[y][x] != Tile::DEFAULT) {
		cout << "Location is already occupied.\n" << endl;
		return false;
	}
	return true;
}

bool Board::placeMove(int x, int y, char tile) {
	if (validInput(x, y)) {
		boardTiles[y][x] = tile;
		return true;
	}
	return false;
}