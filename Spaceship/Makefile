all: main.o field.o draw.o wall.o shuttle.o moveShuttle.o bulletShattle.o myFunctions.o
	g++ field.o draw.o wall.o shuttle.o moveShuttle.o bulletShattle.o myFunctions.o main.o -o Spaceship  -lpthread

main.o:
	g++ -c main.cpp -o main.o

field.o:
	g++ -c field.cpp -o field.o

draw.o:
	g++ -c draw.cpp -o draw.o

shuttle.o:
	g++ -c shuttle.cpp -o shuttle.o

moveShuttle.o:
	g++ -c moveShuttle.cpp -o moveShuttle.o

bulletShattle.o:
	g++ -c bulletShattle.cpp -o bulletShattle.o

wall.o:
	g++ -c wall.cpp -o wall.o

myFunctions.o:
	g++ -c myFunctions.cpp -o myFunctions.o

clean:
	rm -rf *.o
	rm Spaceship
