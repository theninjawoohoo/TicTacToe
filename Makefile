EXENAME = main
TESTEXENAME = tests
OBJS = main.o GameLoop.o Board.o CPU.o
TESTOBJS = tests-main.o Board.o BoardTests.o

CXX = g++
CXXFLAGS = -std=c++11 -c -g -Wall -Wextra
LD = g++
LDFLAGS = -std=c++11 -g -Wall -Wextra

all: $(EXENAME) tests

$(EXENAME): $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

main.o: main.cpp Board.h CPU.h
	$(CXX) $(CXXFLAGS) main.cpp

GameLoop.o: GameLoop.cpp GameLoop.h
	$(CXX) $(CXXFLAGS) GameLoop.cpp

Board.o: Board.cpp Board.h
	$(CXX) $(CXXFLAGS) Board.cpp

CPU.o: CPU.cpp CPU.h
	$(CXX) $(CXXFLAGS) CPU.cpp

$(TESTEXENAME): $(TESTOBJS)
	$(LD) $(TESTOBJS) $(LDFLAGS) -o $(TESTEXENAME)

BoardTests.o: BoardTests.cpp Board.h
	$(CXX) $(CXXFLAGS) BoardTests.cpp

clean:
	rm -f *.o $(EXENAME) $(TESTEXENAME)