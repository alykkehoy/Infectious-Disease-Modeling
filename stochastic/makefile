CXX = g++
CXXFLAGS= -std=c++11

all: test

test:  main.o analytics.o disease.o interaction.o map.o neighborhood.o person.o text_parse.o
	$(CXX) main.o analytics.o disease.o interaction.o map.o neighborhood.o person.o text_parse.o -o test1 

main.o: main.cpp
	$(CXX) -c main.cpp

analytics.o: analytics.cpp analytics.h
	$(CXX) -c analytics.cpp

disease.o: disease.cpp disease.h
	$(CXX) -c disease.cpp

interaction.o: interaction.cpp interaction.h
	$(CXX) -c interaction.cpp

map.o: map.cpp map.h
	$(CXX) $(CXXFLAGS) -c map.cpp

neighborhood.o: neighborhood.cpp neighborhood.h
	$(CXX) -c neighborhood.cpp

person.o: person.cpp person.h
	$(CXX) -c person.cpp

text_parse.o: text_parse.cpp text_parse.h
	$(CXX) -c text_parse.cpp

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $>
	
clean:
	rm test1
	rm *.o
