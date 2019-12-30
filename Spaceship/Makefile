all: main.o functions.o
	g++ main.o functions.o -o Spaceship

main.o:
	g++ -c main.cpp -o main.o

functions.o:
	g++ -c functions.cpp -o functions.o

clean:
	rm -rf *.o
	rm Spaceship
