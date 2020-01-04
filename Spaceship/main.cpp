#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <windows.h>
#include <conio.h>
#include "class.h"
#include "functions.h"

using namespace std;
///////////////////////////////////////////
#define COLUMNS 	70
#define ROWS		20

bool gameOver;
char field[ROWS][COLUMNS];
int score;
string difficulty = "easy";

string menu[5][2];
int input;
string output;
///////////////////////////////////////////
class Wall {
	public:
		Wall(unsigned int value) {
			m_line = value;
			field[m_line][0] = '+';
		}		
		void draw_wall() {
			for (int i = 1; i < COLUMNS; i++) {
				if (field[m_line][i-1] == '-') {
					field[m_line][i] = '+';
				}
				else {
					field[m_line][i] = '-';
				}
			}
		}
		void illusion_of_movement() {
			if (field[m_line][0] == '+') {
				field[m_line][0] = '-';
			}
			else {
				field[m_line][0] = '+';
			}
		}
	private:
		unsigned int m_line;		
};
class Ship {
	public:
		
	private:
	
};
class Obstacle {
	
	public:
		
	private:
	
};
///////////////////////////////////////////
void newGame(),
	 Menu(),
	 Draw(),
	 Input(),
	 Logic(),
	 pause();
///////////////////////////////////////////
int main() {
	system("color 3a");												 //!!!windows
	newGame();
	while (gameOver != true) {
		Menu();	
	 	if (output == "continue") {
		
		}
		else if (output == "newGame") {
			
		}
		else if (output == "save") {
			
			
		}
		else if (output == "load") {
			
			
		}
		else if (output == "help") {
			system("cls");										 	 //!!!windows
			cout << "\n\tHelp\n\n";
			cout << "> Click 'Up' and 'Down' to move Spaceship\n";
			cout << "> From right to left will fly meteorites\n";
			cout << "> Dodge and increase your score\n\n";
			cout << "Developer: Omelchenko Dmitry\n";
			pause();
		}
		
	}
	return 0;
}
///////////////////////////////////////////
void newGame() {
	gameOver = false;
	score = 0;
	difficulty = "easy";
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			field[i][j] = ' ';
		}
	}
}
void Menu() {
	menu[0][0] = "    Continue   "; menu[0][1] = "<";
	menu[1][0] = "    New game   "; menu[1][1] = " ";
	menu[2][0] = "    Save       "; menu[2][1] = " ";
	menu[3][0] = "    Load       "; menu[3][1] = " ";
	menu[4][0] = "    Help       "; menu[4][1] = " ";
	input = 0;
	output = " ";
	
	while (input != 27 && input != 13) {
		system("cls");												 //!!!windows
		cout << "\n\tGame \"Spaceship\"\n";
		cout << "\t      Menu\n\n";
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 2; j++) {
				cout << menu[i][j];
			}
			cout << endl;
		}
		
		input = getch();
		switch (input) {
			case 13:
				if (menu[0][1] == "<") {
					output = "continue";
				}
				else if (menu[1][1] == "<") {
					output = "newGame";
				}
				else if (menu[2][1] == "<") {
					output = "save";
				}
				else if (menu[3][1] == "<") {
					output = "load";
				}
				else if (menu[4][1] == "<") {
					output = "help";
				}
				break;
			case 72:
				if (menu[0][1] == "<") {
					menu[0][1] = " ";
					menu[4][1] = "<";
				}
				else if (menu[1][1] == "<") {
					menu[1][1] = " ";
					menu[0][1] = "<";
				}
				else if (menu[2][1] == "<") {
					menu[2][1] = " ";
					menu[1][1] = "<";
				}
				else if (menu[3][1] == "<") {
					menu[3][1] = " ";
					menu[2][1] = "<";
				}
				else if (menu[4][1] == "<") {
					menu[4][1] = " ";
					menu[3][1] = "<";
				}
				break;
			case 80:
				if (menu[0][1] == "<") {
					menu[0][1] = " ";
					menu[1][1] = "<";
				}
				else if (menu[1][1] == "<") {
					menu[1][1] = " ";
					menu[2][1] = "<";
				}
				else if (menu[2][1] == "<") {
					menu[2][1] = " ";
					menu[3][1] = "<";
				}
				else if (menu[3][1] == "<") {
					menu[3][1] = " ";
					menu[4][1] = "<";
				}
				else if (menu[4][1] == "<") {
					menu[4][1] = " ";
					menu[0][1] = "<";
				}
				
				break;
		}
	}	
}
void Draw() {
		
	Wall wall_up = Wall(0);
	Wall wall_down = Wall(ROWS-1);
	
	while (true) {						//!!!
		system("cls");												 //!!!windows
		wall_up.draw_wall();
		wall_down.draw_wall();
		for (int i = 0; i < ROWS; i++) {
			for (int j = 0; j < COLUMNS; j++) {
				cout << field[i][j];
			}
			cout << endl;
		}
		cout << "Score: " << score << endl;
		wall_up.illusion_of_movement();
		wall_down.illusion_of_movement();
		
		Sleep(200);	
	}
	
}
void Input() {
	
}
void Logic() {
	
}
void pause() {
	cout << "\nPress any key to continue";
	getch();
}
