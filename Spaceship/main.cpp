#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>
#include <ctime>
#include "field.h"
#include "draw.h"
#include "wall.h"

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
	Wall wall_up;
	Wall wall_down;

	while (true) {
	    wall_up.draw_wall(0);
	    wall_down.draw_wall(14);
      painter.print_field(wall_up.getPtrToField(),15,50);
      painter.print_field(wall_down.getPtrToField(),15,50);
	    wall_up.illusion_of_movement_wall(0);
	    wall_down.illusion_of_movement_wall(14);
	    delay(100);
	    system ("clear");
	}
}

void delay(float milliseconds) {
  float value = milliseconds*1000;
  usleep(value);
}
