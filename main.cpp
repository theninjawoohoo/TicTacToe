#include "Board.h"
#include "CPU.h"

using namespace std;

int main() {
	Board board;
	board.printBoard();
	board.placeMove(0, 0, 'X');
	board.printBoard();
	board.placeMove(0, 0, 'O');
	board.printBoard();

	cout << "\nThis is just a test." << endl;

	return 0;
}
