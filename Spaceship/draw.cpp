#include "draw.h"
Draw::Draw() {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			field[i][j] = ' ';
		}
	}
}
void Draw::print_field() {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			std::cout << field[i][j];
		}
		std::cout << std::endl;
	}
}
void Draw::draw_wall(unsigned int m_line) {
	for (int i = 1; i < COLUMNS; i++) {
		if (field[m_line][i-1] == '-') {
			field[m_line][i] = '+';
		}
		else {
			field[m_line][i] = '-';
		}
	}
}
void Draw::illusion_of_movement_wall(unsigned int m_line) {
	if (field[m_line][0] == '+') {
		field[m_line][0] = '-';
	}
	else {
		field[m_line][0] = '+';
	}
}
