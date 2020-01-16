#pragma once
#include "field.h" //!1
class Wall: public gameField //!1
{
	public:
		Wall();
		Wall(unsigned int value);
		void draw_wall(unsigned int m_line);
		void illusion_of_movement_wall(unsigned int m_line);
	private:
		unsigned int m_line;
};
