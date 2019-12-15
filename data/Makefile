all: main.o dataStorage.o
	g++ main.o dataStorage.o

main.o: main.cpp
	g++ -c main.cpp -o main.o

dataStorage.o: dataClass.cpp
	g++ -c dataClass.cpp -o dataStorage.o

clean:
	rm -rf *.o dataClass.o
