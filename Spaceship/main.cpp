#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <ctime>
#include "myFunctions.h"
#include "field.h"
#include "shuttle.h"
#include "moveShuttle.h"
#include "bulletShattle.h"
#include "wall.h"
#include "draw.h"

void* Depict(void*);
void* Input(void*);

MoveShuttle obj_moveShuttle;
Bullet obj_bullets;

int main() {
   pthread_t thread1;
   pthread_t thread2;
   pthread_create(&thread1,NULL,Depict,NULL);
   pthread_create(&thread2,NULL,Input,NULL);
   pthread_join(thread1,NULL);
   pthread_join(thread2,NULL);
   return 0;
}

void* Depict(void*) {
	Wall walls = Wall(0, ROWS-1);
  Shuttle spaceship;
  Draw painter;


	while (true) {
      walls.illusion_of_movement_wall();
      walls.draw_walls();
      spaceship.setField(walls.getPtrToField());
      spaceship.setXandY(obj_moveShuttle.getX(), obj_moveShuttle.getY());
      spaceship.draw();
      if (obj_bullets.get() == true) {
        obj_bullets.setField(spaceship.getPtrToField());
        for (int i = 0; i < obj_bullets.get_i(); i++) {
          obj_bullets.shot();
        }
        painter.print_field(obj_bullets.getPtrToField(),ROWS,COLUMNS);
      }
      else {
        painter.print_field(spaceship.getPtrToField(),ROWS,COLUMNS);
      }
	    delay(100);
	    system ("clear");
	}
}

void* Input(void*) {
  int input;
  while (true) {
    input = getch();
    if (input == 119) {
      obj_moveShuttle.move_up();
    }
    if (input == 115) {
      obj_moveShuttle.move_down();
    }
    if (input == 97) {
      obj_moveShuttle.move_left();
    }
    if (input == 100) {
      obj_moveShuttle.move_right();
    }
    if (input == 32) {
      obj_bullets.set(true);
      obj_bullets.plus();
      obj_bullets.prep(obj_moveShuttle.getX(), obj_moveShuttle.getY());
    }
	}
}
