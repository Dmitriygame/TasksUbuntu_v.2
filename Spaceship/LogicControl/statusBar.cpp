#include "statusBar.h"
StatusBar::StatusBar() {}

StatusBar::~StatusBar() {}

void StatusBar::draw(int energy) {
  setValue(ROWS - 1, 0, 'P');
  setValue(ROWS - 1, 1, 'o');
  setValue(ROWS - 1, 2, 'w');
  setValue(ROWS - 1, 3, 'e');
  setValue(ROWS - 1, 4, 'r');
  setValue(ROWS - 1, 5, ':');
  int a = energy/10;
  if (a == 0) {
    a = -16;
  }
  int b = energy % 10;
  setValue(ROWS - 1, 7, char(a + 48));
  setValue(ROWS - 1, 8, char(b + 48));
}
