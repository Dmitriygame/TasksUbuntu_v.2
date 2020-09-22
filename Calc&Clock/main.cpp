#include "class_Calc.h"
#include "class_Clock.h"
#include "class_Logbook.h"

#include <queue>
#include <pthread.h>
#include <unistd.h>

std::queue<std::string> data;

void* Input(void*);
void* Compute(void*);
void* Time(void*);
void* Output(void*);

int main()
{
  pthread_t thread1;
  pthread_t thread2;
  pthread_t thread3;
  pthread_t thread4;
  pthread_create(&thread1,NULL,Input,NULL);
  pthread_create(&thread2,NULL,Compute,NULL);
  pthread_create(&thread3,NULL,Time,NULL);
  pthread_create(&thread4,NULL,Output,NULL);
  pthread_join(thread1,NULL);
  pthread_join(thread2,NULL);
  pthread_join(thread3,NULL);
  pthread_join(thread4,NULL);
  
  return 0;
}

void* Input(void*) {

}

void* Compute(void*) {

}

void* Time(void*) {
  Clock timer;
  if (data.size() == 0 || data.size() == 1) {
      data.push(timer.output());
  }
}

void* Output(void*) {
  while (true) {
    std::cout << data.size() << "\n";
    std::cout << "Time: " << data.front() << "\n";
    data.pop();
    std::cout << data.size() << "\n";
    std::cout << "Result: " << "\n";
    usleep(1000000);
    system("clear");
  }
}
