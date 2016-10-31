all: test

test:  main.o analytics.o disease.o interaction.o map.o neighborhood.o person.o
	g++ main.o analytics.o disease.o interaction.o map.o neighborhood.o person.o -o test1 

main.o: main.cpp
	g++ -c main.cpp

analytics.o: analytics.cpp analytics.h
	g++ -c analytics.cpp

disease.o: disease.cpp disease.h
	g++ -c disease.cpp

interaction.o: interaction.cpp interaction.h
	g++ -c interaction.cpp

map.o: map.cpp map.h
	g++ -c map.cpp

neighborhood.o: neighborhood.cpp neighborhood.h
	g++ -c neighborhood.cpp

person.o: person.cpp person.h
	g++ -c person.cpp
clean:
	rm test1 
