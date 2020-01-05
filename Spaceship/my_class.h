#pragma once
class Wall {
	public:
		Wall();	
		Wall(unsigned int value);
		void draw_wall();
		void illusion_of_movement();
	private:
		unsigned int m_line;		
};

