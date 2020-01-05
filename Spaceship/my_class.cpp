#include "my_class.h"
Wall::Wall() {
	m_line = value;
	field[m_line][0] = '+';
}
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
