CXX = g++
CXXFLAGS=-std=c++11

all: test
	export LD_LIBRARY_PATH=.

libstoch.so: lib

lib:  Disease.o Compartments/Compartment.o Compartments/S.o Compartments/I.o Compartments/R.o Compartments/E.o Model.o Map.o Person.o
	$(CXX) $^ -o libstoch.so -shared $(CXXLIBS)

test:  Sample.o libstoch.so
	$(CXX) $^ -o Sample -L. -lstoch$(CXXLIBS)
	
%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $< -fPIC -o $@
	
clean:
	rm Sample
	rm *.o
	rm Compartments/*.o
