#ifndef GAMELOOP_H
#define GAMELOOP_H

#include "Board.h"
#include "CPU.h"
#include <iostream>
#include <utility> 

using namespace std;

class GameLoop {
private:
	Board board;
	CPU cpu;
	int turn;

	void handleUserInput();
	void trimSpaces(string &input);
	bool checkLength(string &input);
	pair<int, int> stringToPairInt(string &input);

public:
	GameLoop();

	void run();
};

#endif