#pragma once
class GameOver {
  public:
    GameOver();
    ~GameOver();
    bool get();
    void lose();
    void start();
  private:
    bool gameOver = false;
};
