all: main.o field.o draw.o wall.o shuttle.o moveShuttle.o laserShattle.o myFunctions.o statusBar.o
	g++ field.o draw.o wall.o shuttle.o moveShuttle.o laserShattle.o myFunctions.o statusBar.o main.o -o Spaceship  -lpthread

main.o:
	g++ -c main.cpp -o main.o

field.o:
	g++ -c "Game/field.cpp" -o field.o

draw.o:
	g++ -c "Game/draw.cpp" -o draw.o

shuttle.o:
	g++ -c "Game/shuttle.cpp" -o shuttle.o

moveShuttle.o:
	g++ -c "Game/moveShuttle.cpp" -o moveShuttle.o

laserShattle.o:
	g++ -c "Game/laserShattle.cpp" -o laserShattle.o

wall.o:
	g++ -c "Game/wall.cpp" -o wall.o

myFunctions.o:
	g++ -c "Game/myFunctions.cpp" -o myFunctions.o

statusBar.o:
	g++ -c "LogicControl/statusBar.cpp" -o statusBar.o

clean:
	rm -rf *.o
	rm Spaceship
