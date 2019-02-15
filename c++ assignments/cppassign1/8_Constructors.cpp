#include<iostream>
using namespace std;
class complex {
	int real;
	int img;
public:
	complex() {
		cout << "In default consructor\n";
		real = img = 0;
	}
	complex(int x) {
		cout << "In parameterised constructor\n";
		real = x;
		img = x;
	}
	complex(int x, int y)
	{
		cout << "In two valued parameters:\n";
		real = x;
		img = y;
	}
	complex(complex &c) {
		cout << "In copy constructor:\n";
		real = c.real;
		img = c.img;
	}
	~complex() {
		cout << "In destructor: ";
		cout << real << "+i" << img << endl;
	}


};
int main() {
	complex c1, c2(3), c3(2, 3), c4(c2);
	return 0;


}
