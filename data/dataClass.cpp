#include "dataClass.h"
void DataStorage::set(int value) {
	this->data = value;
}
unsigned int DataStorage::get() {
	return this -> data;
}
DataStorage::DataStorage() {
	data = 0;
}
DataStorage::DataStorage (int num) {
	data = num;
}
DataStorage::~DataStorage() {};
