#include "moveShuttle.h"
#include <cmath>

MoveShuttle::MoveShuttle() {
  m_center_x = round(ROWS/2);
  m_center_y = 1;
}

MoveShuttle::~MoveShuttle() { }

void MoveShuttle::move_up() {
  if (m_center_x != 2)
    --m_center_x;
}

void MoveShuttle::move_down() {
  if (m_center_x != ROWS - 4)
    ++m_center_x;
}

void MoveShuttle::move_left() {
  if (m_center_y != 1)
    --m_center_y;
}

void MoveShuttle::move_right() {
  if (m_center_y != COLUMNS - 5)
    ++m_center_y;
}

int MoveShuttle::getX() {
  return this -> m_center_x;
}
int MoveShuttle::getY() {
  return this -> m_center_y;
}
