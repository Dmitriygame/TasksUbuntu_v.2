#include "bulletShattle.h"
Bullet::Bullet() { }

Bullet::~Bullet() { }

void Bullet::set(bool value) {
  this -> bShot = value;
}

bool Bullet::get() {
  return this -> bShot;
}

void Bullet::prep(int x, int y) {
  this -> m_x = x;
  this -> m_y = y;
}

void Bullet::shot() {
  m_y = m_y + coefficient;
  if (m_y < COLUMNS - 1) {
    setValue(m_x, m_y, '=');
//    ++coefficient;
  }
  else {
    setValue(m_x, m_y, ' ');
    set(false);
  }
}
