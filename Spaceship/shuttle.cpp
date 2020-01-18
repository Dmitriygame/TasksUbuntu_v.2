#include "shuttle.h"
#include <cmath>
Shuttle::Shuttle() {
  m_center = round(ROWS/2);
}

void Shuttle::draw() {
  setValue(m_center,1,'*');
  setValue(m_center,2,'*');
  setValue(m_center,3,'*');
  setValue(m_center,4,'*');
  setValue(m_center,5,'*');
  setValue(m_center+1,1,'*');
  setValue(m_center+1,2,'*');
  setValue(m_center+1,3,'*');
  setValue(m_center+1,4,'*');
  setValue(m_center+1,5,'*');
  setValue(m_center-1,1,'*');
  setValue(m_center-1,2,'*');
  setValue(m_center+2,1,'*');
  setValue(m_center+2,2,'*');
}

void Shuttle::move_up() {
  if (m_center != 2)
    --m_center;
}

void Shuttle::move_down() {
  if (m_center != ROWS - 5)
    ++m_center;
}
//ssssssdddddddddddd
