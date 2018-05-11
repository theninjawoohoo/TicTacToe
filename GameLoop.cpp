#include "GameLoop.h"
#include <iostream>
#include <utility> 

using namespace std;

GameLoop::GameLoop() {
	board = Board();
	cpu = RandomCPU();
	turn = 0;
}

void GameLoop::run() {
	board.printBoard();
	cout << "Enter a xy cooridinate to place a tile (e.g. 02).\n" << endl;

	while(true) {
		if (turn % 2 == 0) {
			handleUserInput();
		} else {
			cpu.placeMove(board);
		}
		turn++;
		cout << endl;
		board.printBoard();
		cout << endl;
		if (turn >= 5)
			if (board.checkForWinner())
				break;
		if (turn == 9) {
			cout << "There was a tie." << endl;
			break;
		}
	}
}

void GameLoop::handleUserInput() {
	string input;
	do {
		cout << "Enter a xy coordinate: ";
		getline(cin, input);
		trimSpaces(input);
	}
	while (!validInput(input));

	pair<int,int> coords = stringToPairInt(input);
	board.placeMove(coords.first, coords.second, board.Tile::X);
}

void GameLoop::trimSpaces(string &input) {
	for (unsigned int i = 0; i < input.length(); i++) {
		if (input.at(i) == ' ') {
			input.erase(i, 1);
			i--;
		}
 	}
}

bool GameLoop::validInput(string &input) {
	if (!validLength(input)) {
		cout << "Invalid number of coordinates.\n" << endl;
		return false;
	}
	pair<int,int> coords = stringToPairInt(input);
	return board.validInputPrint(coords.first, coords.second);
}

bool GameLoop::validLength(string &input) {
	return input.length() == 2;
}

pair<int,int> GameLoop::stringToPairInt(string &input) {
	//48 is the ascii code for 0.
	int x = input.at(0) - 48;
	int y = input.at(1) - 48;
	return make_pair(x, y);
}