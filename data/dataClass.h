#pragma once
class DataStorage {
	public:
		void set(int value);
		unsigned int get();
		DataStorage();
		DataStorage (int num);
		~DataStorage();
	private:
		unsigned int data;
};
