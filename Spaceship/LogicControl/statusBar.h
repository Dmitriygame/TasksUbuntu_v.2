#pragma once
#include "../Game/field.h"

class StatusBar: public gameField {
  public:
    StatusBar();
    ~StatusBar();
    void draw_HP(int health_points);
    void draw_power(int energy);
};
