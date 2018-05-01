#include <iostream>
#include "GameLoop.h"

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