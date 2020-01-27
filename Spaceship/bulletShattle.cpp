#include "bulletShattle.h"
Bullet::Bullet() { }

Bullet::~Bullet() { }

void Bullet::set(bool value) {
  this -> bShot = value;
}

bool Bullet::get() {
  return this -> bShot;
}

int Bullet::get_i() {
  return this -> m_i;
}

void Bullet::plus() {
  this -> m_i = this -> m_i + 1;
}

void Bullet::minus() {
  if (m_i > 0) {
    this -> m_i = this -> m_i - 1;
  }
}

void Bullet::prep(int x, int y) {
  this -> m_x1 = x - 1;
  this -> m_y1 = y + 2;
  this -> m_x2 = x + 2;
  this -> m_y2 = y + 2;
}

void Bullet::shot() {
  m_y1 = m_y1 + coefficient;
  m_y2 = m_y2 + coefficient;
  if (m_y1 < COLUMNS - 1) {
    setValue(m_x1, m_y1, '=');
    setValue(m_x2, m_y2, '=');
  }
  else {
    setValue(m_x1, m_y1, ' ');
    setValue(m_x2, m_y2, ' ');
    minus();
  }
}
