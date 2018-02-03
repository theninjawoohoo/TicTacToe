//This is a computer player class

#ifndef CPU_H
#define CPU_H

#include <iostream>
#include "Board.h"

using namespace std;



class computerPlayer {
private:
	bool isTheirTurn;

public:
	computerPlayer();
	computerPlayer(bool isTheirTurn);

	void calculateMove(Board theGameBoard);
};

#endif 