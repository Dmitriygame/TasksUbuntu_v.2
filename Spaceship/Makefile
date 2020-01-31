PATH_FOLDER_GAME += $(PWD)/Game/
PATH_FOLDER_LOGIC += $(PWD)/LogicControl/


all: main.o field.o draw.o wall.o shuttle.o moveShuttle.o laserShattle.o myFunctions.o statusBar.o
	g++ field.o draw.o wall.o shuttle.o moveShuttle.o laserShattle.o myFunctions.o statusBar.o main.o -o Spaceship  -lpthread

main.o:
	g++ -c main.cpp -o main.o

field.o:
	g++ -c $(PATH_FOLDER_GAME)field.cpp -o field.o

draw.o:
	g++ -c $(PATH_FOLDER_GAME)draw.cpp -o draw.o

shuttle.o:
	g++ -c $(PATH_FOLDER_GAME)shuttle.cpp -o shuttle.o

moveShuttle.o:
	g++ -c $(PATH_FOLDER_GAME)moveShuttle.cpp -o moveShuttle.o

laserShattle.o:
	g++ -c $(PATH_FOLDER_GAME)laserShattle.cpp -o laserShattle.o

wall.o:
	g++ -c $(PATH_FOLDER_GAME)wall.cpp -o wall.o

myFunctions.o:
	g++ -c $(PATH_FOLDER_GAME)myFunctions.cpp -o myFunctions.o

statusBar.o:
	g++ -c $(PATH_FOLDER_LOGIC)statusBar.cpp -o statusBar.o

clean:
	rm -rf *.o
	rm Spaceship
