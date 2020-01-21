#pragma once
#include "field.h"
class Shuttle: public gameField {
	public:
		Shuttle();
		void draw();
		void setXandY(int x, int y);
	private:
		int m_center_x, m_center_y;
};
