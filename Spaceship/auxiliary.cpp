#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <windows.h>
#include <conio.h>

//#include <string.h>


using namespace std;
///////////////////////////////////////////




///////////////////////////////////////////
int main() {
	system("color 3a");	
	
	string a = "asd";
	cout << a <<  endl;
	if (a == "asd") {
		cout << "asdasd\n";
	}
	a = "hjgkkkksd";
	if (a == "hjgkkkksd") {
		cout << "000\n";
	}

	return 0;
}



/*





void Menu() {
	string menu[5][15] = 
	{ {"    Continue   "},
	  {"    New game   "},
	  {"    Save       "},
	  {"    Load       "},
	  {"    Help       "} };
//	char cursor = '>';
	menu[0][1] = "<";
	
	
	while (input != 27) {
		system("cls");													 //!!!windows
		cout << "\n\tGame \"Spaceship\"\n";
		cout << "\t      Menu\n\n";
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				cout << menu[i][j];
			}
			cout << endl;
		}
		
		input = getch();
		switch (input) {
			case 13:
				
				break;
			case 72:
				if (menu[0][1] == "<") {
					menu[0][1] = " ";
					menu[4][1] = "<";
				}
				break;
			case 80:
				
				break;
		}
	}
	
}


		

#include "functions.h"
Wall::Wall(unsigned int value) {
	m_line = value;
	field[m_line][0] = '+';
}		
void Wall::draw_wall() {
	for (int i = 1; i < COLUMNS; i++) {
		if (field[m_line][i-1] == '-') {
			field[m_line][i] = '+';
		}
		else {
			field[m_line][i] = '-';
		}
	}
}
void Wall::illusion_of_movement() {
	if (field[m_line][0] == '+') {
		field[m_line][0] = '-';
	}
	else {
		field[m_line][0] = '+';
	}
}






#pragma once
class Wall {
	public:
		Wall(unsigned int value);	
		void draw_wall();
		void illusion_of_movement();
	private:
		unsigned int m_line;		
};











*/
