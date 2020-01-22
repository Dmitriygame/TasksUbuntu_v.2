#include "draw.h"
Draw::Draw() { }
Draw::~Draw() { }
void Draw::print_field(char** arr, unsigned int row, unsigned int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			std::cout << arr[i][j];
		}
	 std::cout << std::endl;
	}
}
