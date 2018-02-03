EXENAME = main
OBJS = main.o Board.o CPU.o

CXX = g++
CXXFLAGS = -c -g -Wall -Wextra
LD = g++
LDFLAGS = -g -Wall -Wextra

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