#pragma once
#include "field.h"
class Laser: public gameField {
  public:
    Laser();
    ~Laser();
    void set(bool value);
    bool get();
    void prep(int x, int y);
    void shot();
    int get_power();
    void plusPow();
    void minusPow();
  private:
    bool bShot = false;
    int m_x1, m_y1;
    int m_power = 30, maxPower = 30;
};
