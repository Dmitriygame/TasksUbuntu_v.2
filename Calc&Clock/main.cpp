#include "class_Calc.h"
#include "class_Clock.h"
#include "class_Logbook.h"

#include <queue>
#include <thread>
#include <unistd.h>
#include <mutex>
std::mutex mute;

std::queue<std::string> data;

void Input(void);
void Compute(void);
void Time(void);
void Output(void);

int main()
{
  std::thread th1 (Time);
  std::thread th2 (Output);
  th1.join();
  th2.join();

  return 0;
}

void Input(void) {

}

void Compute(void) {

}

void Time(void) {

  Clock timer;
      while(true)
      {
         mute.lock();
         data.push(timer.output());
         mute.unlock();
         usleep(1000000);
      }

}

void Output(void) {
  while (true) {
    if(!data.empty())
    {
      mute.lock();
      std::cout << data.size() << "\n";
      std::cout << "Time: " << data.front() << "\n";
      data.pop();
      std::cout << data.size() << "\n";
      std::cout << "Result: " << "\n";
      mute.unlock();
    }
    usleep(1000000);
    system("clear");
  }
}
