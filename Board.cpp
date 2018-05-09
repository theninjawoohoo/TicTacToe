//Includes board.h and makes the definitions

#include "Board.h"
#include <iostream>

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
	
	for(int y = 0; y < OLD_BOARD_SIZE; y++) {
		cout << y << " | ";
		for(int x = 0; x < OLD_BOARD_SIZE; x++) {	
			int locationOfTile = x + 3 * y;

			if(boardTiles[locationOfTile] == Tile::DEFAULT) {
				cout << " "; 
			}
			else if(boardTiles[locationOfTile] == Tile::X) {
				cout << "X";
			}
			else {
				cout << "O";
			}

			cout << " ";
		}
		cout << "|" << endl;
	}
	cout << BORDER_TOP << endl;
	cout << "    0 1 2" << endl;
}

bool Board::checkForWinner() {
	return checkRows() || checkColumns() || checkDiagonals();
}

bool Board::checkRows() {

	for (int i = 0; i < OLD_BOARD_SIZE; i++) {
		short left = boardTiles[3*i];
		short mid = boardTiles[3*i + 1];
		short right = boardTiles[3*i + 2];
		if (left == mid && left == right && left != Tile::DEFAULT) {
			cout << mid << " won the game!" << endl;
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
			cout << mid << " won the game!" << endl;
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
		char winner;
		if(mid == 0) {
			winner = 'O';
		}
		else {
			winner = 'X';
		}


		cout << winner << " won the game!" << endl;
		return true;
	}
	//Checks diagonal top right to bottom left
	if (topRight == mid && botLeft == mid && mid!= Tile::DEFAULT) {
		char winner;
		if(mid == 0) {
			winner = 'O';
		}
		else {
			winner = 'X';
		}
		cout << winner << " won the game!" << endl;
		return true;
	}

	return false;
}

bool Board::inBounds(int x, int y) {
	return x < OLD_BOARD_SIZE && x >= 0 && y < OLD_BOARD_SIZE && y >= 0;
}

bool Board::unoccupied(int x, int y) {
	int userInputTranslation = x + 3 * y;
	return boardTiles[userInputTranslation] == Tile::DEFAULT;
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

void Board::placeMove(int x, int y, short tile) {
	int userInputTranslation = x + 3 * y;
	boardTiles[userInputTranslation] = tile;
}