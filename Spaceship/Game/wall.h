#pragma once
#include "field.h"
class Wall: public gameField
{
	public:
		Wall();
		~Wall();
		Wall(unsigned int value1, unsigned int value2);
		void draw_walls();
		void illusion_of_movement_wall();
	private:
		unsigned int m_line1;
		unsigned int m_line2;
};
