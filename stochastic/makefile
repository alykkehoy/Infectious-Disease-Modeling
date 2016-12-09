CXX = g++
CXXFLAGS=-std=c++11

all: test

test:  sample.o disease.o interaction.o States/State.o States/S.o States/I.o States/R.o States/E.o Model.o map.o neighborhood.o person.o
	#$(CXX) main.o analytics.o disease.o interaction.o S.o I.o R.o SIR.o SIRS.o SEIR.o Model.o map.o neighborhood.o person.o -o test1 
	$(CXX) $^ -o test1 $(CXXLIBS)
	
%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
clean:
	rm *.o
	rm States/*.o