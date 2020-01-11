#pragma once
#define COLUMNS 50
#define ROWS 15

class gameField
{
   //char field[ROWS][COLUMNS];
   char **field;
   public:
   gameField();
   void setValue (unsigned int x, unsigned y, char value);
   char getValue(unsigned int x,unsigned int y);
   char** getPtrToField();
   ~gameField();
};


class Wall: public gameField
{
	public:
		Wall();
		Wall(unsigned int value);
		void draw_wall(unsigned int m_line);
		void illusion_of_movement_wall(unsigned int m_line);
	private:
		unsigned int m_line;
};
