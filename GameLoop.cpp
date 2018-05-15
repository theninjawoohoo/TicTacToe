#include "GameLoop.h"
#include <iostream>
#include <utility> 
#include <limits>

using namespace std;

GameLoop::GameLoop() {
	board = Board();
	turn = 0;
}

void GameLoop::run() {
	setDifficulty();
	board.printBoard();
	cout << "\nEnter a xy cooridinate to place a tile (e.g. 02)." << endl;

	while(true) {
		if (turn == 9) {
			cout << "There was a tie." << endl;
			break;
		}
		//Players turn on even turns
		(turn % 2 == 0) ? handleUserInput() : cpu->placeMove(board);
		cout << endl;
		board.printBoard();
		cout << endl;
		if (turn >= 4)
			if (board.checkForWinner()) {
				printWinner(turn);
				break;
			}
		turn++;
	}
}

void GameLoop::setDifficulty() {
	int input;
	do {
		cout << "Select the difficulty: 1-easy, 2-hard." << endl;
		cin >> input;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	while (input < 1 || input > 2);

	(input == 1) ? cpu = new RandomCPU() : cpu = new MinMaxCPU();
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

void GameLoop::printWinner(int turn) {
	string winner;
	(turn % 2 == 0) ? winner = "X" : winner = "O";
	cout << winner << " won the game!" << endl;
}