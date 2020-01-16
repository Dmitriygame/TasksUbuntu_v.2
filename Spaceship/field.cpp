#include "field.h"

gameField::gameField()
{
	field = new char*[ROWS];
	for (int i=0; i<ROWS; i++)
	field[i] = new char[COLUMNS];
}

void gameField::setValue(unsigned int x, unsigned y, char value)
{
   this->field[x][y] = value;
}

char gameField::getValue(unsigned int x, unsigned y)
{
   return this->field[x][y] ;
}

char **gameField::getPtrToField()
{
   return field;
}

gameField::~gameField()
{
		for (int i=0; i<COLUMNS; i++)
		delete[] field[i];
		delete[] field;
}

void gameField::clearField() {
  for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			setValue(i,j,' ');
		}
	}
}
