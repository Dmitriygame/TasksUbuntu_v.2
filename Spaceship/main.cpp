#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <ctime>
#include "Game/myFunctions.h"
#include "Game/field.h"
#include "Game/shuttle.h"
#include "Game/moveShuttle.h"
#include "Game/laserShattle.h"
#include "Game/wall.h"
#include "Game/draw.h"
#include "LogicControl/statusBar.h"

void* Depict(void*);
void* Input(void*);

MoveShuttle obj_moveShuttle;
Laser obj_laser;

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
	Wall walls = Wall(0, ROWS-2);
  Shuttle spaceship;
  Draw painter;
  StatusBar statusBar;


	while (true) {
      walls.illusion_of_movement_wall();
      walls.draw_walls();
      spaceship.setField(walls.getPtrToField());
      spaceship.setXandY(obj_moveShuttle.getX(), obj_moveShuttle.getY());
      spaceship.draw();
       if (obj_laser.get() == true) {
        obj_laser.setField(spaceship.getPtrToField());
        obj_laser.prep(obj_moveShuttle.getX(), obj_moveShuttle.getY());
        obj_laser.shot();
        obj_laser.minusPow();
        spaceship.setField(obj_laser.getPtrToField());
        if (obj_laser.get_power() == 0)
          obj_laser.set(false);
      }
      else obj_laser.plusPow();
      statusBar.setField(spaceship.getPtrToField());
      statusBar.draw(obj_laser.get_power());
      painter.print_field(statusBar.getPtrToField(),ROWS,COLUMNS);
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
      if (obj_laser.get() == true) {
        obj_laser.set(false);
      }
      else obj_laser.set(true);
   }
	}
}
