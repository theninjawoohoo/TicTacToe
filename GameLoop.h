#ifndef GAMELOOP_H
#define GAMELOOP_H

#include "Board.h"
#include "RandomCPU.h"
#include "MinMaxCPU.h"
#include <iostream>
#include <utility> 

using namespace std;

class GameLoop {
private:
	Board board;
	CPU* cpu;
	int turn;

	void setDifficulty();
	void handleUserInput();
	void trimSpaces(string &input);
	bool validInput(string &input);
	bool validLength(string &input);
	pair<int,int> stringToPairInt(string &input);
	void printWinner(int turn);

public:
	GameLoop();

	void run();
};

#endif