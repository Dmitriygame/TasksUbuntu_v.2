#pragma once
#include "gameDefines.h"
class MoveShuttle {
	public:
		MoveShuttle();
		~MoveShuttle();
		void move_up();
		void move_down();
		void move_left();
		void move_right();
		int getX();
		int getY();
  private:
    int m_center_x, m_center_y;
};
