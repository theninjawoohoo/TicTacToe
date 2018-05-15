//RandomCPU.cpp
#include <iostream>
#include "RandomCPU.h"

using namespace std;

RandomCPU::RandomCPU() {
	srand(time(NULL));
}

void RandomCPU::placeMove(Board &board) {
  	int x;
	int y;

	do {
		x = rand() % 3;
		y = rand() % 3;
	}
	while (!board.validInput(x, y));
	board.placeMove(x, y, board.Tile::O);
}