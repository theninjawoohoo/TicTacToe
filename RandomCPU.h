//RandomCPU.h
#ifndef RANDOMCPU_H
#define RANDOMCPU_H

#include "Board.h"
#include "CPU.h"

using namespace std;

class RandomCPU : public CPU {
public:
  RandomCPU();
  void placeMove(Board &board);
};

#endif 
