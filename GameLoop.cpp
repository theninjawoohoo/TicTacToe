#include "GameLoop.h"
#include <iostream>
#include <utility> 

using namespace std;

GameLoop::GameLoop() {
	board = Board();
	cpu = CPU();
	turn = 0;
}

void GameLoop::run() {
	board.printBoard();
	cout << "Enter a xy cooridinate to place a tile (e.g. 02).\n" << endl;

	while(turn < 9) {
		if (turn % 2 == 0) {
			handleUserInput();
		} else {
			cpu.placeMove(board);
		}
		board.printBoard();
		cout << endl;
		turn++;
	}
}

void GameLoop::handleUserInput() {

}

void GameLoop::trimSpaces(string &input) {
	for (unsigned int i = 0; i < input.length(); i++) {
		if (input.at(i) == ' ')
			input.erase(i, 1);
 	}
}

bool GameLoop::checkLength(string &input) {
	return input.length() != 2;
}

pair<int, int> GameLoop::stringToPairInt(string &input) {
	//48 is the ascii code for 0.
	int x = input.at(0) - 48;
	int y = input.at(1) - 48;
	return make_pair(x, y);
}