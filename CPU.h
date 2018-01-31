//This is a computer player class

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


}
