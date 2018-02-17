//Includes board.h and makes the definitions

#include "Board.h"

using namespace std;

Board::Board() {
	//This is a for that initialize the board to all blank tiles.			
	for(int x = 0; x < BOARD_SIZE; x++) {
		for(int y = 0; y < BOARD_SIZE; y++) {
			boardTiles[y][x] = Tile::DEFAULT;
		}
	}
}


void Board::printBoard() {
	//This is for printing out the board.
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

void Board::checkForWinner() {

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

	//Check first diagonal
	char tile = boardTiles[0][0];
	for(int i = 0; i < BOARD_SIZE; i++) {
		if(tile != boardTiles[i][i] || tile == '_') {
			break;
		}
		return true;
	}

	//Check the other diagonal
	tile = boardTiles[BOARD_SIZE - 1][0];
	int horizantalCoordinates = 1;
	
	for(int verticalCoordinates = 1; verticalCoordinates < BOARD_SIZE; verticalCoordinates++) {
		if(tile != boardTiles[horizantalCoordinates][verticalCoordinates] || tile == '_') {
			break;
		}
		horizantalCoordinates--;
		return true;
	}

	return false;
}

bool Board::validInput(int x, int y) {
	if (x < 0 || x > BOARD_SIZE - 1 || y < 0 || y > BOARD_SIZE - 1) {
		cout << "Location is out of bounds.\n" << endl;
		return false;
	} else if (boardTiles[y][x] != Tile::DEFAULT) {
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