//Includes board.h and makes the definitions

#include "Board.h"

using namespace std;

Board::Board() {
	//This is a for that initialize the board to all blank tiles.			
	for(int i = 0; i < MAX_SIZE; i++) {
		for(int j = 0; j < MAX_SIZE; j++) {
			boardTiles[i][j] = Tile::DEFAULT;
		}
	}
}


void Board::printBoard() {
	//This is for printing out the board.
	const string BORDER_TOP = "  +-------+";

	cout << "    0 1 2" << endl;
	cout << BORDER_TOP << endl;
	for(int i = 0; i < MAX_SIZE; i++) {
		cout << i << " | ";
		for(int j = 0; j < MAX_SIZE; j++) {	
			cout << boardTiles[i][j] << " ";
		}
		cout << "|" << endl;
	}
	cout << BORDER_TOP << endl;
}

void Board::checkForWinner() {

}

bool Board::checkRows() {
	bool checkIfWinner = false;

	//Checks the rows semi-efficiently
	for(int i = 0; i < MAX_SIZE; i++) {
		char tile = boardTiles[i][0];
		for(int j = 1; j < MAX_SIZE; j++) {
			if(boardTiles[i][j] != tile || tile == '_') {
				break;
			}
			checkIfWinner = true;
		}
	}
	
	return checkIfWinner;
}	

bool Board::checkColumns() {
	bool checkIfWinner = false;

	//Checks the columns semi-efficiently 
	for(int i = 0; i < MAX_SIZE; i++) {
		char tile = boardTiles[0][i];

		for(int j = 1; j < MAX_SIZE; i++) {
			if(boardTiles[j][i] != tile || tile == '_') {
				break;
			}
			checkIfWinner = true;
		}
	}

	return checkIfWinner;
}

bool Board::checkDiagonals() {

	//Check first diagonal
	char tile = boardTiles[0][0];
	for(int i = 0; i < MAX_SIZE; i++) {
		if(tile != boardTiles[i][i] || tile == '_') {
			break;
		}
		return true;
	}

	//Check the other diagonal
	tile = boardTiles[MAX_SIZE - 1][0];
	int horizantalCoordinates = 1;
	
	for(int verticalCoordinates = 1; verticalCoordinates < MAX_SIZE; verticalCoordinates++) {
		if(tile != boardTiles[horizantalCoordinates][verticalCoordinates] || tile == '_') {
			break;
		}
		horizantalCoordinates--;
		return true;
	}

	return false;
}

bool Board::validInput(int x, int y) {
	if (x < 0 && x > MAX_SIZE && y < 0 && y > MAX_SIZE) {
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