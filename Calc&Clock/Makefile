all: main.o calc.o clock.o logbook.o
	g++ main.o --std=c++14 calc.o clock.o logbook.o -o Calc -pthread

main.o: main.cpp
	g++ -c main.cpp -o main.o

calc.o:
	g++ -c class_Calc.cpp -o calc.o

clock.o:
	g++ -c class_Clock.cpp -o clock.o

logbook.o:
	g++ -c class_Logbook.cpp -o logbook.o

clean:
	rm -rf *.o
	rm Calc
