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
   void clearField();
   ~gameField();
};
