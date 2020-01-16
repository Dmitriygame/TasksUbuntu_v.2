#include "wall.h"

Wall::Wall() {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			this->setValue(i,j,' ');
		}
	}
}

Wall::Wall(unsigned int value) {
}

void Wall::draw_wall(unsigned int m_line) {
	for (int i = 1; i < COLUMNS; i++) {
		if (this->getValue(m_line,i-1) == '-') {
			this->setValue(m_line,i,'+');
		}
		else {
			this->setValue(m_line,i,'-');
		}
	}
}

void  Wall::illusion_of_movement_wall(unsigned int m_line) {
	if (this->getValue(m_line,0) == '+') {
		this->setValue(m_line,0,'-');
	}
	else {
		this->setValue(m_line,0,'+');
	}
}
