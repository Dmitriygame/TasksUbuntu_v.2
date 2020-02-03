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
  }
}

void Obstacle::draw() {
  if (centerX == 1) {
    for (int i  = centerX; i < height; i++)
      setValue(i, centerY, '#');
  }
  if (centerX == ROWS - 3) {
    for (int i  = centerX; i > height + 6; i--)
      setValue(i, centerY, '#');
  }
}

void Obstacle::move() {
  if (centerY != 1) {
    --centerY;
  }
  else existence = false;
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
