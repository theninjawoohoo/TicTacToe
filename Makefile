EXENAME = main
OBJS = main.o Board.o CPU.o

CXX = g++
CXXFLAGS = -std=c++11 -c -g -Wall -Wextra
LD = g++
LDFLAGS = -std=c++11 -g -Wall -Wextra

all: $(EXENAME)

$(EXENAME): $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

main.o: main.cpp Board.h CPU.h
	$(CXX) $(CXXFLAGS) main.cpp

Board.o: Board.cpp Board.h cmpt_error.h
	$(CXX) $(CXXFLAGS) Board.cpp

CPU.o: CPU.cpp CPU.h cmpt_error.h
	$(CXX) $(CXXFLAGS) CPU.cpp

clean:
	rm -f *.o $(EXENAME)