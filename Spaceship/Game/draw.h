#pragma once
#include <iostream>

class Draw {
	public:
		Draw();
		~Draw();
		void print_field(char** arr, unsigned int row, unsigned int col);
};
