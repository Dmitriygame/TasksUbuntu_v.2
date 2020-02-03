#include "health.h"
Health::Health() {}
Health::~Health() {}
int Health::get() {
 return this -> HP;
}
void Health::set(int value) {
  this -> HP = value;
}
void Health::plus(int value) {
  if (HP < 100)
    this -> HP += value;
}
void Health::minus(int value) {
  if (HP > 0)
    this -> HP -= value;
}
