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
	for(int x = 0; x < BOARD_SIZE; x++) {
		cout << x << " | ";
		for(int y = 0; y < BOARD_SIZE; y++) {	
			cout << boardTiles[y][x] << " ";
		}
		cout << "|" << endl;
	}
	cout << BORDER_TOP << endl;
}

void Board::checkForWinner() {

}

bool Board::checkRows() {
	// bool checkIfWinner = false;
	// //Checks the rows semi-efficiently
	// for(int x = 0; x < BOARD_SIZE; x++) {
	// 	char tile = boardTiles[x][0];
	// 	for(int y = 1; y < BOARD_SIZE; y++) {
	// 		if(boardTiles[x][y] != tile || tile == '_') {
	// 			break;
	// 		}
	// 		checkIfWinner = true;
	// 	}
	// }
	
	// return checkIfWinner;

	for (int y = 0; y < BOARD_SIZE; y++) {
		char leftTile = boardTiles[y][0];
		char middleTile = boardTiles[y][1];
		char rightTile = boardTiles[y][2];
		if (leftTile == middleTile && leftTile == rightTile && leftTile != Tile::DEFAULT)
			return true;
	}
	return false;
}	

bool Board::checkColumns() {
	bool checkIfWinner = false;

	//Checks the columns semi-efficiently 
	for(int i = 0; i < BOARD_SIZE; i++) {
		char tile = boardTiles[0][i];

		for(int j = 1; j < BOARD_SIZE; i++) {
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