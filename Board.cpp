//Includes board.h and makes the definitions

#include "Board.h"

using namespace std;

Board::Board() {
	//This is a for that initialize the board to all blank tiles.			
	for(int i = 0; i < MAX_SIZE + 1; i++) {
		for(int j = 0; j < MAX_SIZE + 1; j++) {
			boardTiles[i][j] = Tile::DEFAULT;
		}
	}
}


void Board::printBoard() {
	//This is for printing out the board.
	const string BORDER_TOP = "  +-------+";

	cout << "    0 1 2" << endl;
	cout << BORDER_TOP << endl;
	for(int i = 0; i < MAX_SIZE + 1; i++) {
		cout << i << " | ";
		for(int j = 0; j < MAX_SIZE + 1; j++) {	
			cout << boardTiles[i][j] << " ";
		}
		cout << "|" << endl;
	}
	cout << BORDER_TOP << endl;
}

void Board::checkForWinner() {

}

bool Board::checkIfValidInput(int x, int y) {
	return (x >= 0 && x <= MAX_SIZE &&
	 		y >= 0 && y <= MAX_SIZE && 
	 		boardTiles[y][x] == Tile::DEFAULT);
}

void Board::placeMove(int x, int y) {
	
}