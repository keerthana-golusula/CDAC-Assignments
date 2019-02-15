#include<iostream>
using namespace std;
class Complex {
	float real;
	float img;
public:
	Complex() {
		real = img = 0;
	}
	Complex(float x) {
		real=x;
		img = x;
	}
	Complex(float x, float y) {
		real = x;
		img = y;
	}
	void display() {
		cout << real << "+i" << img << endl;
	}
	friend Complex Add(Complex& , Complex&);
	friend Complex Mul(Complex& , Complex&);

};
Complex Add(Complex& c1, Complex& c2) {
	Complex temp;
	temp.real = c1.real+c2.real;
	temp.img = c1.img + c2.img;
	return temp;
}
Complex Mul(Complex& c1, Complex& c2) {
	Complex temp;
	temp.real = c1.real*c2.real - (c1.img*c2.img);
	temp.img = c1.real*c2.img + (c1.img*c2.real);
	return temp;
}
int main() {
	Complex c1(1), c2(2, 3), c3, c4;
	cout << "c1 is:";
	c1.display();
	cout << "c2 is:";
	c2.display();
	c3 = Add(c1, c2);
	cout << "After addition:";
	c3.display();
	c4 = Mul(c1, c2);
	cout << "After multiplication:";
	c4.display();

}