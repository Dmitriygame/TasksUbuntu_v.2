#pragma once
class Health {
  public:
    Health();
    ~Health();
    int get();
    void set(int value);
    void plus(int value);
    void minus(int value);
  private:
    int HP = 100;
};
