all: main.o field.o draw.o wall.o shuttle.o
	g++ field.o draw.o wall.o shuttle.o main.o -o Spaceship  -lpthread

main.o:
	g++ -c main.cpp -o main.o

field.o:
	g++ -c field.cpp -o field.o

draw.o:
	g++ -c draw.cpp -o draw.o

shuttle.o:
	g++ -c shuttle.cpp -o shuttle.o

wall.o:
	g++ -c wall.cpp -o wall.o

clean:
	rm -rf *.o
	rm Spaceship
