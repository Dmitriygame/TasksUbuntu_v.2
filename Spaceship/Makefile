all: main.o draw.o wall.o
	g++ draw.o wall.o main.o -o Spaceship  -lpthread

main.o:
	g++ -c main.cpp -o main.o

draw.o:
	g++ -c draw.cpp -o draw.o

wall.o:
	g++ -c wall.cpp -o wall.o

clean:
	rm -rf *.o
	rm Spaceship
