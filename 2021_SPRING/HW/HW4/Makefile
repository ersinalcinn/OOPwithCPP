main: main.o gates.o
	g++ -std=c++11 main.o gates.o -o main
	rm ./gates.o
	rm ./main.o

gates.o: gates.cpp
	g++ -std=c++11 -c gates.cpp

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

