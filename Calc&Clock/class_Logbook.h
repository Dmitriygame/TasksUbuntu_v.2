#pragma once
#include <iostream>
#include <vector>
#include <string>

class Logbook {
  public:
    Logbook();
    ~Logbook();
    void input();

  private:
    std::vector<char> journal;
};
