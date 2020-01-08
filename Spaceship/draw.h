#pragma once
#include <iostream>
#define COLUMNS 70
#define ROWS 20
class Draw {
	public:
		Draw();
		void print_field();
		void draw_wall(unsigned int m_line);
		void illusion_of_movement_wall(unsigned int m_line);
	private:
		char field[ROWS][COLUMNS];
};
