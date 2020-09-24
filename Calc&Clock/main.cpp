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

std::mutex mtx;
std::condition_variable cv;
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
  while(true) {
     std::unique_lock <std::mutex> ulm (mtx);
     std::cout << "Time"<< "\n";
     ulm.unlock();
     cv.notify_one();
     std::this_thread::sleep_for(std::chrono::milliseconds(1000));  
  }
}

void Output(void) {
  while (true) {
    std::unique_lock <std::mutex> ulm (mtx);
    cv.wait(ulm,[](){return !data.empty();});
    std::cout << "Output:" << "\n";
    ulm.unlock();
  }
}

