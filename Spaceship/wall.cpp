#include "wall.h"

Wall::Wall() {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			this->setValue(i,j,' ');
		}
	}
}

Wall::Wall(unsigned int value1, unsigned int value2) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			this->setValue(i,j,' ');
		}
	}
	this -> m_line1 = value1;
	this -> m_line2 = value2;
}
/*
unsigned int Wall::get() {
	return this -> m_line;
}*/

void Wall::draw_walls() {
	for (int i = 1; i < COLUMNS; i++) {
		if (this->getValue(m_line1,i-1) == '-') {
			this->setValue(m_line1,i,'+');
		}
		else {
			this->setValue(m_line1,i,'-');
		}
	}
	for (int i = 1; i < COLUMNS; i++) {
		if (this->getValue(m_line2,i-1) == '-') {
			this->setValue(m_line2,i,'+');
		}
		else {
			this->setValue(m_line2,i,'-');
		}
	}
}

void  Wall::illusion_of_movement_wall() {
	if (this->getValue(m_line1,0) == '+') {
		this->setValue(m_line1,0,'-');
	}
	else {
		this->setValue(m_line1,0,'+');
	}
	if (this->getValue(m_line2,0) == '+') {
		this->setValue(m_line2,0,'-');
	}
	else {
		this->setValue(m_line2,0,'+');
	}
}
