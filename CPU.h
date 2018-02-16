//This is a computer player class

#ifndef CPU_H
#define CPU_H

#include <iostream>
#include "Board.h"

using namespace std;



class CPU {
private:
	int difficulty;

public:
	CPU(int difficulty);

	void calculateMove(Board theGameBoard);
	void placeMove(int rowLocation, int columnLocation); 
	bool isValidMove(Board theGameBoard);
};

#endif 