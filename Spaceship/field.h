#pragma once
#define COLUMNS 60
#define ROWS 20
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
   void setField(char **arr);
   ~gameField();
};
