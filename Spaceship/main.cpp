#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>
#include <ctime>
#include "draw.h"
#include "wall.h"

using namespace std;
void delay(float milliseconds);
void* Depict(void*);

int main() {
   pthread_t thread;
   pthread_create(&thread,NULL,Depict,NULL);
   pthread_join(thread,NULL);
   return 0;
}

void* Depict(void*) {
	Draw painter;
	Wall wall_up = Wall(0);
	Wall wall_down = Wall(ROWS-1);

	while (true) {
	    painter.draw_wall(wall_up.get());
	    painter.draw_wall(wall_down.get());
      painter.print_field();
	    painter.illusion_of_movement_wall(wall_up.get());
	    painter.illusion_of_movement_wall(wall_down.get());
	    delay(100);
	    system ("clear");
	}
}

void delay(float milliseconds) {
  float value = milliseconds*1000;
  usleep(value);
}
