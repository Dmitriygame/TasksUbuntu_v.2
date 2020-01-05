#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include "my_class.h"

using namespace std;
void* Draw(void*);

int main() {
   pthread_t thread;
   pthread_create(&thread,NULL,Draw,NULL);
   pthread_join(thread,NULL);
   return 0;
}

void* Draw(void*) {
   Wall wall_up = Wall(0);
   Wall wall_down = Wall(ROWS-1);

   while (true) {
      wall_up.draw_wall();
      wall_down.draw_wall();
      wall_up.printWall();
      wall_down.printWall();
      wall_up.illusion_of_movement();
      wall_down.illusion_of_movement();
      sleep(1);
      system ("clear");
   }
}
