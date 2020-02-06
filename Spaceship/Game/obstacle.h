#pragma once
#include "field.h"
#include "gameDefines.h"
class Obstacle: public gameField {
  public:
    Obstacle();
    ~Obstacle();
    void create();
    void draw();
    void move();
    void wait_plus();
    bool get_existence();
    void set_existence(bool value);
    void setValueFense(unsigned int x, char value);
    char getValueFense(unsigned int x);
  private:
    int centerX, centerY, height, wait = 0, max_wait = 9;
    bool existence = false;
    char *fense = new char[height];
};
