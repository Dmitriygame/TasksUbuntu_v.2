#pragma once
#include<iostream>
#define COLUMNS 70
#define ROWS 10

class Wall {
	public:
		Wall();
		Wall(unsigned int value);
		void draw_wall();
		void illusion_of_movement();
		void printWall();
	private:
		unsigned int m_line;
		char field[ROWS][COLUMNS];
};
