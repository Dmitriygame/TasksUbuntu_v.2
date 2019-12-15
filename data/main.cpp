#include <iostream>
#include "dataClass.h"

using namespace std;

int main() {
	DataStorage obj;
	obj.set(12);
	cout << obj.get() << endl;

	return 0;
}
