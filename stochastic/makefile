
run:  main.o disease.o map.o neighborhood.o 
	g++ main.o disease.o map.o neighborgood.o -o run

main.o: main.cpp
	g++ -c main.o

disease.o: disease.cpp disease.h
	g++ -c disease.cpp

map.o: map.o map.h
	g++ -c map.cpp

neighborhood.o: neighborhood.cpp neighborhood.h
	g++ -c neighborhood.cpp

clean:
	rm *.o run 
