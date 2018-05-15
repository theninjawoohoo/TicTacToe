
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
  int maxMove(Board board, bool isCPU, int depth, int bestScore);
  int minMove(Board board, bool isCPU, int depth, int bestScore);
  int bestMove(Board board);
  bool gameOver(Board board);
  int evaluate(Board board, bool isCpu);

};

#endif 
