#include "laserShattle.h"
Laser::Laser() { }

Laser::~Laser() { }

void Laser::set(bool value) {
  this -> bShot = value;
}

bool Laser::get() {
  return this -> bShot;
}

void Laser::prep(int x, int y) {
  this -> m_x1 = x;
  this -> m_y1 = y + 5;
}

void Laser::shot() {
  for (int i = m_y1; i < COLUMNS; i++) {
    setValue(m_x1, i, '=');
  }
}

int Laser::get_power() {
  return this -> m_power;
}

void Laser::plusPow() {
  if (m_power < maxPower)
    ++m_power;
}

void Laser::minusPow() {
  if (m_power > 0)
    --m_power;
}
