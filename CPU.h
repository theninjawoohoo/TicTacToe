//This is a computer player class

#ifndef CPU_H
#define CPU_H

#include <iostream>
#include "Board.h"

using namespace std;



class computerPlayer {
private:
	int difficulty;

public:
	computerPlayer(int difficulty);

	void calculateMove(Board theGameBoard);
	void placeMove(int rowLocation, int columnLocation); 
	bool isValidMove(Board theGameBoard);



#endif 