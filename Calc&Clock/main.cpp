#include "class_Calc.h"
#include "class_Clock.h"
#include "class_Logbook.h"

#include <queue>
#include <thread>
#include <unistd.h>
#include <mutex>
#include <cstdio>

std::mutex mute;
std::queue<std::string> data;

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
  std::string inp;
  while(true) {
    mute.lock();
    data.push("inp");
    mute.unlock();
    usleep(1000000);
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
     usleep(1000000);
  }
}

void Output(void) {
  while (true) {
    if(!data.empty()) {
      mute.lock();
      std::cout << "Time: " << data.front() << "\n";
      data.pop();
      std::cout << "Result: " << "\n";
      std::cout << "Input: " << data.front() << "\n";
      data.pop();
      mute.unlock();
    }
    usleep(1000000);
    system("clear");
  }
}
