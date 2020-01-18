#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>
#include <ctime>
#include "field.h"
#include "shuttle.h"
#include "wall.h"
#include "draw.h"

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
	Wall walls = Wall(0, ROWS-1);
  Shuttle spaceship;

	while (true) {

      walls.illusion_of_movement_wall();
	    walls.draw_walls();
      spaceship.setField(walls.getPtrToField());
      spaceship.draw();
      painter.print_field(spaceship.getPtrToField(),ROWS,COLUMNS);

	    delay(100);
	    system ("clear");
	}
}

void delay(float milliseconds) {
  float value = milliseconds*1000;
  usleep(value);
}
