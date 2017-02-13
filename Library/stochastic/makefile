CXX = g++
CXXFLAGS=-std=c++11

all: test

test:  Sample.o Disease.o Compartments/Compartment.o Compartments/S.o Compartments/I.o Compartments/R.o Compartments/E.o Model.o Map.o Person.o
	$(CXX) $^ -o test1 $(CXXLIBS)
	
%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
clean:
	rm *.o
	rm Compartments/*.o
