// complex class and usage of friend function.
#include<iostream>
#include<string>
using namespace std;
class Complex {
	float real;
	float img;
public:
	// default constructor
	Complex() {
		real = img = 0;
	}
	// parameter constructor
	Complex(float x) {
		real=x;
		img = x;
	}
	// parametrised constructor
	Complex(float x, float y) {
		real = x;
		img = y;
	}
	void display() {
		cout << real << "+" << img << "i"<<endl;
	}
	// friend functions
	friend Complex addComplex(Complex& , Complex&);
	friend Complex mulComplex(Complex& , Complex&);

};
// addition of two complex numbers
Complex addComplex(Complex& c1, Complex& c2) {
	Complex temp;
	temp.real = c1.real+c2.real;
	temp.img = c1.img + c2.img;
	return temp;
}
// multiplication of two complex numbers
Complex mulComplex(Complex& c1, Complex& c2) {
	Complex temp;
	temp.real = c1.real*c2.real - (c1.img*c2.img);
	temp.img = c1.real*c2.img + (c1.img*c2.real);
	return temp;
}
int main() {
	Complex c1(1), c2(2, 3), c3, c4;// objects initializing with various types of constructors
	cout << "c1 is: ";
	c1.display();
	cout << "c2 is: ";
	c2.display();
	c3 = addComplex(c1, c2);
	cout << "After addition: ";
	c3.display();
	c4 = mulComplex(c1, c2);
	cout << "After multiplication: ";
	c4.display();

}
