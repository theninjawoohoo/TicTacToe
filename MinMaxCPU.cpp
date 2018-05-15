//MinMaxCPU.cpp
#include <iostream>
#include "MinMaxCPU.h"
#include <climits>
#include <vector>

using namespace std;
MinMaxCPU::MinMaxCPU() {}

void MinMaxCPU::placeMove(Board &board) {
	int location = bestMove(board);
	board.placeMove(location, board.Tile::O);
}

int MinMaxCPU::minMax(Board board, int depth, bool isCpu) {
	int score = evaluate(board, isCpu);

	if(score == 10) {
		return score - depth;
	}

	if(score == -10) {
		return score + depth;
	}

	if(gameOver(board)) {
		return 0;
	}

	if(isCpu) {
		int bestScore = INT_MAX;
		bestScore = minMove(board, isCpu, depth, bestScore);
		return bestScore;
	} else {
		int bestScore = INT_MIN;
		bestScore = maxMove(board, isCpu, depth, bestScore);
		return bestScore;
	}
}

int MinMaxCPU::maxMove(Board board, bool isCPU, int depth, int bestScore) {
	vector<int> moves = board.possibleMoves();
	for(unsigned int i = 0; i < moves.size(); i++) {
		board.placeMove(moves.at(i), board.Tile::O);
		bestScore = max(bestScore, minMax(board, depth+1, !isCPU));
		board.placeMove(moves.at(i), Board::DEFAULT);
	}
	return bestScore;
}

int MinMaxCPU::minMove(Board board, bool isCPU, int depth, int bestScore) {
	vector<int> moves = board.possibleMoves();
	for(unsigned int i = 0; i < moves.size(); i++) {
		board.placeMove(moves.at(i), board.Tile::X);
		bestScore = min(bestScore, minMax(board, depth+1, !isCPU));
		board.placeMove(moves.at(i), board.Tile::DEFAULT);
	}
	return bestScore;
}

//Returns the location for the best possible move
int MinMaxCPU::bestMove(Board board) {
	//Assume the current best is the worst outcome
	int bestValue = INT_MIN;
	int bestMoveIndex;

	//Get a list of a possible locations for a move. Then we hypothetically place a CPU move and evaulate the board state.
	//Do this for every possible move
	vector<int> moves = board.possibleMoves();
	for(unsigned int i = 0; i < moves.size(); i++) {
		//Places the move
		board.placeMove(moves.at(i), board.Tile::O);

		//Evaluates a score for this move. We must look ahead by using minmax
		int moveValue = minMax(board, 0, true);

		//Undo the move placement
		board.placeMove(moves.at(i), board.Tile::DEFAULT);

		if(moveValue > bestValue) {
			bestMoveIndex = moves.at(i);
			bestValue = moveValue;
		}
	}

	return bestMoveIndex;
}

bool MinMaxCPU::gameOver(Board board) {
	return board.possibleMoves().empty();
}

int MinMaxCPU::evaluate(Board board, bool isCpu) {
	int score;
	if(board.checkForWinner()) {
		isCpu ? score = 10 : score = -10;
	}
	else {
		score = 0;
	}
	return score;
}
