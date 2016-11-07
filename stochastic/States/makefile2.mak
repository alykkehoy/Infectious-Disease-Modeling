CXX = g++
CXXFLAGS=-std=c++11

all: test

test: State.o S.o I.o R.o 
	$(CXX) State.o S.o I.o R.o -o test1 

State.o: State.cpp State.h
	$(CXX) -c State.cpp
	
S.o: S.cpp S.h
	$(CXX) -c S.cpp
	
I.o: I.cpp I.h
	$(CXX) -c I.cpp
	
R.o: R.cpp R.h
	$(CXX) -c R.cpp

clean:
	rm test2
	rm *.o 
