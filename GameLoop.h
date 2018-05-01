#ifndef GAMELOOP_H
#define GAMELOOP_H

#include <iostream>
#include "Board.h"
#include "CPU.h"

using namespace std;

class GameLoop {
private:
	Board board;
	CPU cpu;
	int turn;

	void handleUserInput();
	void trimSpaces(string &input);

public:
	GameLoop();

	void run();
};

#endif