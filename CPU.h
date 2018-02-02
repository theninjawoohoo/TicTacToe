//This is a computer player class

#ifndef CPU_H
#define CPU_H

#include <iostream>
#include "cmpt_error.h"

using namespace std;

class computerPlayer {
private:
	boolean isTheirTurn;


public:
	computerPlayer();
	computerPlayer(boolean isTheirTurn);

	void calculateMove(Board theGameBoard);
};

#endif