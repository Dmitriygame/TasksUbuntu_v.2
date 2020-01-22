#include "myFunctions.h"
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

void delay(float milliseconds) {
  float value = milliseconds*1000;
  usleep(value);
}

int getch() {
	struct termios oldt,
	newt;
	int ch;
	tcgetattr( STDIN_FILENO, &oldt );
	newt = oldt;
	newt.c_lflag &= ~( ICANON | ECHO );
	tcsetattr( STDIN_FILENO, TCSANOW, &newt );
	ch = getchar();
	tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
	return ch;
}
