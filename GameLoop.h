#ifndef GAMELOOP_H
#define GAMELOOP_H

#include "Board.h"
#include "CPU.h"
#include <iostream>

using namespace std;

class GameLoop {
private:
	Board board;
	CPU cpu;
	int turn;

	void handleUserInput();
	void trimSpaces(string &input);
	bool checkLength(string &input);

public:
	GameLoop();

	void run();
};

#endif