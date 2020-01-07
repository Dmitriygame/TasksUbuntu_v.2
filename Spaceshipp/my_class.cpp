#include "my_class.h"
Field::Field() {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			field[i][j] = ' ';
		}
	}
}
char Field::get() {
	return this -> field[ROWS][COLUMNS];
}
Wall::Wall() {
}
Wall::Wall(unsigned int value) {
	m_line = value;
	field[m_line][0] = '+';
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			field[i][j] = ' ';
		}
	}
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
Draw::Draw() {
}
void Draw::printField(char array[ROWS][COLUMNS]) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			std::cout << array[i][j];
		}
		std::cout << std::endl;
	}
}
