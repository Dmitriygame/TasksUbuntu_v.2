#include "class_Calc.h"
#include "class_Clock.h"
#include "class_Logbook.h"

#include <queue>
#include <thread>
#include <unistd.h>
#include <mutex>
#include <cstdio>
#include <stdio.h>
#include <termios.h>
#include <condition_variable>

std::mutex mute;
std::mutex mtx;
std::condition_variable cv;
bool var = false;
bool ret() {return var;}
std::queue<std::string> data;

int getch();
void Input(void);
void Compute(void);
void Time(void);
void Output(void);

int main()
{
  std::thread th1 (Time);
  std::thread th2 (Compute);
  std::thread th3 (Input);
  std::thread th4 (Output);
  th1.join();
  th2.join();
  th3.join();
  th4.join();

  return 0;
}

void Input(void) {
  while(true) {

  }
}

void Compute(void) {

}

void Time(void) {
  Clock timer;
  while(true) {
     mute.lock();
     data.push(timer.output());
     mute.unlock();
     var = true;
     cv.notify_one();
     usleep(1000000);
  }
}

void Output(void) {
  while (true) {
    std::unique_lock <std::mutex> ulm (mtx);
    cv.wait(ulm, ret);
    if(!data.empty()) {
      std::cout << "Time: " << data.front() << "\n";
      data.pop();
      std::cout << "Result:" << "\n";
      std::cout << "Input:" << "\n";
      mute.unlock();
      usleep(1000000);
      system("clear");
      var = false;
    }
  }
}

int getch() {
	struct termios oldt,
	newt;
	int ch;
	tcgetattr( STDIN_FILENO, &oldt );
	newt = oldt;
	newt.c_lflag &= ~( ICANON | ECHO );
	tcsetattr( STDIN_FILENO, TCSANOW, &newt );
	ch = getchar();
	tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
	return ch;
}
