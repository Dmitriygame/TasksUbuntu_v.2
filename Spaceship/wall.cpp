#include "wall.h"
Wall::Wall() {
}
Wall::Wall(unsigned int value) {
	m_line = value;
}
unsigned int Wall::get() {
	return this -> m_line;
}
