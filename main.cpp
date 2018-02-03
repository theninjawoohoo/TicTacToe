#include "Board.h"
#include "CPU.h"

using namespace std;

int main() {
	Board board;
	board.printBoard();
	board.placeMove(2, 0, 'X');
	board.printBoard();
	board.placeMove(2, 1, 'O');
	board.printBoard();

	cout << "\nThis is just a test." << endl;

	return 0;
}
