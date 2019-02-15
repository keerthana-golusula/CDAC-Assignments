#include<iostream>
using namespace std;
class complex {
	float real;
	float img;
public:
	complex() {
		real = float = 0;
	}
	complex(float a, float b) {
		real = a;
		img = b;
	}
	complex(complex c) {
		real = c.real;
		img = c.img;
	}
	~complex() {
		cout << "in destructor";
	}
	complex operator+(complex c) {
		complex res;
		res.real = real + c.real;
		res.img = img + c.img;
		return res;
	}

	complex operator-(complex c) {
		complex res;
		res.real = real - c.real;
		res.img = img - c.img;
		return res;
	}
	complex operator++() {
		return (complex(real++, img++));
	}
	complex operator++(int x)
	{
		complex temp;
		temp.real = ++real;
		temp.img = ++img;
		return temp;
	}


	complex operator-() {
		complex temp;
		temp.real = -real;
		temp.img = -img;
		return temp;
	}
	complex operator,(complex c) {
		return c;
	}
	/*complex operator=(complex c) {
		real = c.real;
		img = c.img;
		
	complex* operator->() {
		return this;
	}*/
	friend ostream& operator<<(ostream& , complex c);
	friend istream& operator>>(istream& , complex &c);
};

ostream& operator<<(ostream& cout, complex c) {
	cout << c.real << "+i" << c.img << endl;
	return cout;
}
istream& operator >> (istream& cin, complex &c) {
	cin >> c.real >> c.img;
	return cin;
}

int main() {
	complex c1, c2(2.0, 3.0), c3(c2), c4, c5;
	//cin >> c1;
	cout << "c1:" << c1 << " c2:" << c2 << " c3:" < c3 << endl;
	c4 = c1 + c2;
	cout << "c1+c2:";
		cout << c4 << endl;
	c4 = c1 - c2;
	cout << "c1-c2:";
		cout << c4 << endl;
	cout << "-c3";
		c5 = -c3;
	cout << c5 << endl;
	cout << "(c1,c2,c3):";
	c5 = (c1, c2, c3);
//	cout << c5<<endl;
	cout << "c5->real:";
//	cout << c5->real << endl;


}