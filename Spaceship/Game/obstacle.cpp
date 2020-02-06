#include "obstacle.h"
#include <stdlib.h>
#include <ctime>
Obstacle::Obstacle() {
  srand(time(0));
}

Obstacle::~Obstacle() {}

void Obstacle::create() {
  if (this -> wait == max_wait) {
    int value;
    this -> centerY = COLUMNS - 1;
    this -> height = rand() % 4 + 5;
    value = rand() % 2;
    if (value == 0)
      this -> centerX = 1;
    else {
      this -> centerX = ROWS - 3;
    }
    this -> existence = true;
    for (int i = 0; i < height; i++) {
      setValueFense(i, '#');
    }
  }
}

void Obstacle::draw() {
    int j;
    if (centerX == 1) {
      j = 0;
      for (int i  = centerX; i < height; i++) {
        if (getValue(i, centerY) == '=') {
          setValueFense(j, ' ');
        }
        else {
          setValue(i, centerY, getValueFense(j));
        }
        ++j;
      }
    }
    if (centerX == ROWS - 3) {
      j = centerX;
      for (int i = 0; i < height; i++) {
        if (getValue(j, centerY) == '=') {
          setValueFense(i, ' ');
        }
        else {
          setValue(j, centerY, getValueFense(i));
        }
        --j;
      }
    }
}

void Obstacle::move() {
  if (centerY != 1) {
    --centerY;
  }
  else  {
    existence = false;
    delete [] fense;
  }
}

void Obstacle::wait_plus() {
  this -> wait = (this -> wait < max_wait) ? ++wait : 0;

}

bool Obstacle::get_existence() {
  return this -> existence;
}

void Obstacle::set_existence(bool value) {
  this -> existence = value;
}

void Obstacle::setValueFense(unsigned int x, char value) {
  this -> fense[x] = value;
}
char Obstacle::getValueFense(unsigned int x) {
  return this -> fense[x];
}
