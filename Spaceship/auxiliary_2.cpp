#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <windows.h>
#include <conio.h>
using namespace std;
int input;
int main() {
	
	while (true) {
		input = getch();
		cout << input << endl;
		if (input == 72) {
			cout << "up\n";
		}
		if (input == 80) {
			cout << "down\n";
		}
	}
	return 0;
}



/*
day 1:
	install Dev-C++
	create the skeleton of the program
day 2,3:
	create Draw(), class Wall, Menu()
day 4:
	Sasha saw the project
	create help
	



*/
