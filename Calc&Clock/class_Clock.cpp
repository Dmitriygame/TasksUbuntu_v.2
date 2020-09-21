#include "class_Clock.h"
#include <iostream>
Clock::Clock() {}

Clock::~Clock() {}

std::string Clock::output() {
  time_t rawtime;
  struct tm * timeinfo;
  char buffer[10];
  time (&rawtime);
  timeinfo = localtime(&rawtime);
  strftime (buffer,10, "%I:%M:%S",timeinfo);
  std::string time = buffer;
  std::cout<<"==============>"<<buffer;
  return time;
}
