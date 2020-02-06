#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <ctime>
#include "Game/myFunctions.h"
#include "Game/field.h"
#include "Game/shuttle.h"
#include "Game/health.h"
#include "Game/moveShuttle.h"
#include "Game/laserShattle.h"
#include "Game/wall.h"
#include "Game/obstacle.h"
#include "Game/draw.h"
#include "Game/gameOver.h"
#include "Game/score.h"
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
  Health HP;
  Obstacle fense;
  Obstacle fense2;
  Obstacle fense3;
  Obstacle fense4;
  Obstacle fense5;
  StatusBar statusBar;
  Draw painter;



	while (true) {
      walls.illusion_of_movement_wall();
      walls.draw_walls();
      spaceship.setField(walls.getPtrToField());
      spaceship.setXandY(obj_moveShuttle.getX(), obj_moveShuttle.getY());

      if (obj_laser.get() == true) {
        obj_laser.setField(spaceship.getPtrToField());
        obj_laser.prep(obj_moveShuttle.getX(), obj_moveShuttle.getY());
        obj_laser.shot();
        obj_laser.minusPow();
        spaceship.setField(obj_laser.getPtrToField());
      }
      else obj_laser.plusPow();

      fense.wait_plus();

      fense.setField(spaceship.getPtrToField());
      if (fense.get_existence() == false)
        fense.create();
      else {
        fense2.wait_plus();
        fense.draw();
        fense.move();
      }

      fense2.setField(fense.getPtrToField());
      if (fense2.get_existence() == false)
        fense2.create();
      else {
        fense3.wait_plus();
        fense2.draw();
        fense2.move();
      }

      fense3.setField(fense2.getPtrToField());
      if (fense3.get_existence() == false)
        fense3.create();
      else {
        fense4.wait_plus();
        fense3.draw();
        fense3.move();
      }

      fense4.setField(fense3.getPtrToField());
      if (fense4.get_existence() == false)
        fense4.create();
      else {
        fense5.wait_plus();
        fense4.draw();
        fense4.move();
      }

      fense5.setField(fense4.getPtrToField());
      if (fense5.get_existence() == false)
        fense5.create();
      else {
        fense5.draw();
        fense5.move();
      }

      spaceship.setField(fense5.getPtrToField());
      spaceship.draw();

      statusBar.setField(spaceship.getPtrToField());
      statusBar.draw_power(obj_laser.get_power());
      statusBar.draw_HP(HP.get());
      painter.print_field(statusBar.getPtrToField(),ROWS,COLUMNS);

      obj_laser.set(false);
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
    if (input == 32 && obj_laser.get_power() > 0) {
      obj_laser.set(true);
   }
	}
}
