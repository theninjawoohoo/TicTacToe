#include "GameLoop.h"

using namespace std;

int main() {
	Board board;
	board.placeMove(0, 0, 'X');
	board.placeMove(1, 0, 'X');
	board.placeMove(2, 0, 'O');
	board.placeMove(0, 1, 'O');
	board.placeMove(1, 1, 'O');
	board.placeMove(2, 1, 'X');
	board.placeMove(0, 2, 'X');
	board.placeMove(1, 2, 'X');
	board.placeMove(2, 2, 'O');

	board.printBoard();


	cout << "Winner? " << board.checkForWinner() << endl;

	return 0;
}
