#pragma once
#include "field.h"
class Bullet: public gameField {
  public:
    Bullet();
    ~Bullet();
    void set(bool value);
    bool get();
    int get_i();
    void plus();
    void minus();
    void prep(int x, int y);
    void shot();
  private:
    bool bShot = false;
    int m_x1, m_y1, m_x2, m_y2;
    int coefficient = 3;
    int m_i = 0;
};
