#pragma once
#include "field.h"
class Bullet: public gameField {
  public:
    Bullet();
    ~Bullet();
    void set(bool value);
    bool get();
    void prep(int x, int y);
    void shot();
  private:
    bool bShot = false;
    int m_x, m_y;
    int coefficient = 3;
};
