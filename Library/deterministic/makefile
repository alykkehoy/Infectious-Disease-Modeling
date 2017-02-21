CXX = g++
CXXFLAGS=-std=c++11

all: test1 test2 test3

libstoch.so: lib


test1:  Sir_model.o
	$(CXX) $^ -o Sir_model $(CXXLIBS)

test2:  Sirs_model.o
	$(CXX) $^ -o Sirs_model $(CXXLIBS)

test3:  Sis_model.o
	$(CXX) $^ -o Sis_model $(CXXLIBS)

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $< -fPIC -o $@
	
clean:
	rm *.o
	rm Sir_model
	rm Sirs_model
	rm Sis_model
