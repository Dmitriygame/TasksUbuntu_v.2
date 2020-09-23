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

std::mutex mute;
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
    mute.lock();
    std::string i = "i ";
    i[1] = char(99);
    data.push(i);
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
     data.push("t" + timer.output());
     mute.unlock();
     usleep(1000000);
  }
}

void Output(void) {
  while (true) {
    if(!data.empty()) {
      mute.lock();
      std::string m = data.front();
      if (m[0] == 't') {
        m[0] = ' ';
        std::cout << "Time:" << m << "\n";
        data.pop();
      }
      std::cout << "Result:" << "\n";
      std::cout << "Input:" << data.front() << "\n";
      data.pop();
      mute.unlock();
    }
    usleep(1000000);
    system("clear");
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
