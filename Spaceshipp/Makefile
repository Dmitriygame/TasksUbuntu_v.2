all: main.o my_class.o
	g++ my_class.o main.o -o Spaceship  -lpthread

main.o:
	g++ -c main.cpp -o main.o

my_class:
	g++ -c my_class.cpp -o my_class.o

clean:
	rm -rf *.o
	rm Spaceship
