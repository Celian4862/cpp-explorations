#include <iostream>
using namespace std;

class integer {
	private:
		const int value;
	public:
		integer (int x) : value(x) {}
		void printValue() const {
			cout << value << endl;
		}
};

class testing {
	private:
		int x = 0;
		int a;
	public:
		testing (int y, int z) : a (z) {
			cout << y << endl << z << endl;
		}
};

int main(){
	const integer i (2);
	i.printValue();
	int y = 8, z = 3;
	testing t (y, z);

    return 0;

}