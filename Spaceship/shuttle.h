#pragma once
#include "field.h"
class Shuttle: public gameField {
	public:
		Shuttle();
		void draw();
		void move_up();
		void move_down();
	private:
		int m_center;
};
