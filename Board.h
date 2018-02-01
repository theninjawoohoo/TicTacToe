#include <iostream>
#include "cmpt_error.h"

using namespace std;

class Board {
private:
	const int maxSize = 2;
	char boardTiles[maxSize][maxSize];	

public:
	Board();

	void printBoard();
	void checkForWinner();
	bool checkIfValidInput();
	void placeMove();


}


