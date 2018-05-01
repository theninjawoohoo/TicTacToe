//This is a computer player class

#ifndef CPU_H
#define CPU_H

#include <iostream>
#include "Board.h"

using namespace std;

class CPU {
public:
	CPU();

	void placeMove(Board &board);
};

#endif 