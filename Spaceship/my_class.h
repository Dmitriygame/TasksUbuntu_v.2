#pragma once
#include <iostream>
#define COLUMNS 70
#define ROWS 10

class Field {
	public:
		Field();
		char get();
//		friend class Draw;
	protected:
		char field[ROWS][COLUMNS];
};
class Wall : public Field {
	public:
		Wall();
		Wall(unsigned int value);
		void draw_wall();
		void illusion_of_movement();
	private:
		unsigned int m_line;
};
class Draw {
	public:
		Draw();
		void printField(char array[ROWS][COLUMNS]);
};
