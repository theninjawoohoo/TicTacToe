//This is a computer player class

#ifndef CPU_H
#define CPU_H

#include "Board.h"

using namespace std;

class CPU {
public:
	CPU();

	virtual void placeMove(Board &board) = 0;
};

#endif 