#include "Board.h"
#include "CPU.h"

using namespace std;

int main() {
	Board board;
	board.printBoard();
	board.placeMove(0, 2, 'O');
	board.placeMove(1, 1, 'O');
	board.placeMove(2, 0, 'O');
	board.printBoard();
	bool checkC = board.checkColumns();
	bool checkR = board.checkRows();
	bool checkD = board.checkDiagonals();


	cout << "\nThis is just a test." << endl;
	cout << "Did columns have a winner: " << checkC << endl;
	cout << "Did rows have a winner: " << checkR << endl;
	cout << "Did diagonals have a winner: " << checkD << endl;




	return 0;
}
