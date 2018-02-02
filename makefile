#This is the basic makefile for the project.
#http://mrbook.org/blog/tutorials/make/ <- Here is where I learnt to make the makefile
#CPFlags are options we can pass to the compiler
#We can also assign variables instead of calling g++ all the time.

CC=g++

all: main

main: main.o Board.o CPU.o
	$(CC) Board.o CPU.o -o main

main.o: main.cpp
	$(CC) -c main.cpp

Board.o : Board.cpp Board.h
	$(CC) -c Board.cpp

CPU.o: CPU.cpp CPU.h
	$(CC) -c CPU.cpp

clean:
	rm *o main
