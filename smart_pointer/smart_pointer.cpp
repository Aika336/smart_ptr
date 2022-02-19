#include "smart_ptr.h"

int main() {

	int* a = new int(2);
	smart_ptr<int> ptr(a);

	std::cout << *ptr << " " << a;
	return 0;
}