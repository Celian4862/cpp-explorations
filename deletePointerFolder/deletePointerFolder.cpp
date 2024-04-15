#include <iostream>
using namespace std;

int ptrReturn (int a) {
	return a;
}

int main() {
	int a = 10;
	int *ptr = &a;
	
	cout << *ptr << endl;
    // Throws a warning because it's not on the heap, but that's the point of this project
	delete ptr;
	
	ptr = new int;
	*ptr = 8;
	cout << *ptr << endl;
	
	delete ptr;
	cout << *ptr << endl;
	
	*ptr = NULL;
	
	return 0;
}