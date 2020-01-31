#pragma once
#include "/../Game/field.h"

class StatusBar: public gameField {
  public:
    StatusBar();
    ~StatusBar();
    void draw(int energy);
};
