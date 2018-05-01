
#include <iostream>
#include "CPU.h"

using namespace std;

CPU::CPU() {
	//Initialize random number generator
	srand(time(NULL));
}

//Places a tile at a random valid location on given board
void CPU::placeMove(Board &board) {
	int x;
	int y;

	do {
		x = rand() % 3;
		y = rand() % 3;
	}
	while (!board.validInput(x, y));
	board.placeMove(x, y, board.Tile::O);
}
