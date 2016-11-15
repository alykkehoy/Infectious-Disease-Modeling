CXX = g++
CXXFLAGS=-std=c++11

all: test

test: State.o S.o I.o R.o 
	$(CXX) State.o S.o I.o R.o -o test1 

State.o: State.cpp State.h
	$(CXX) $(CXXFLAGS) -c State.cpp
	
S.o: S.cpp S.h
	$(CXX) $(CXXFLAGS) -c S.cpp
	
I.o: I.cpp I.h
	$(CXX) $(CXXFLAGS) -c I.cpp
	
R.o: R.cpp R.h
	$(CXX) $(CXXFLAGS) -c R.cpp

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $>
	
clean:
	rm test2
	rm *.o 
