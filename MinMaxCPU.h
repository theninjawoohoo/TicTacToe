
//MinMaxCPU.h
#ifndef MINMAXCPU_H
#define MINMAXCPU_H

#include "Board.h"
#include "CPU.h"

using namespace std;

class MinMaxCPU : public CPU {
public:
  MinMaxCPU();
  void placeMove(Board &board);
private: 
  int minMax(Board board, int depth, bool isCpu);
  int max(Board board);
  int min(Board board);
  int bestMove(Board board);
  bool checkForEndGame(Board board);
  int findScoreOfBoardState(Board board, bool isCpu);
  
  int evaluateRows();
  int evaluateColumns();
  int evaluateDiagonals();


};

#endif 