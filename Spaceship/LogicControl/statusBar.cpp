#include "statusBar.h"
StatusBar::StatusBar() {}

StatusBar::~StatusBar() {}

void StatusBar::draw_HP(int health_points) {
  setValue(ROWS - 1, 0, 'H');
  setValue(ROWS - 1, 1, 'P');
  setValue(ROWS - 1, 2, ':');
  int a = health_points/100;
  if (a == 0) {
    a = -16;
  }
  int b = (health_points % 100)/10;
  if (a == 32 && b == 0) {
    b = -16;
  }
  int c = health_points % 10;
  setValue(ROWS - 1, 4, char(a + 48));
  setValue(ROWS - 1, 5, char(b + 48));
  setValue(ROWS - 1, 6, char(c + 48));
}

void StatusBar::draw_power(int energy) {
  setValue(ROWS - 1, 8, 'P');
  setValue(ROWS - 1, 9, 'o');
  setValue(ROWS - 1, 10, 'w');
  setValue(ROWS - 1, 11, 'e');
  setValue(ROWS - 1, 12, 'r');
  setValue(ROWS - 1, 13, ':');
  int a = energy/10;
  if (a == 0) {
    a = -16;
  }
  int b = energy % 10;
  setValue(ROWS - 1, 14, char(a + 48));
  setValue(ROWS - 1, 15, char(b + 48));
}
