#include "shuttle.h"
#include <cmath>
Shuttle::Shuttle() { }

Shuttle::~Shuttle() { }

void Shuttle::draw() {
  for (int i = m_center_y; i < m_center_y + 5; i++) {
    if (i < m_center_y + 2) {
      setValue(m_center_x-1,i,'*');
      setValue(m_center_x+2,i,'*');
    }
    setValue(m_center_x,i,'*');
    setValue(m_center_x+1,i,'*');
  }
}

void Shuttle::setXandY(int x, int y) {
  this -> m_center_x = x;
  this -> m_center_y = y;
}
