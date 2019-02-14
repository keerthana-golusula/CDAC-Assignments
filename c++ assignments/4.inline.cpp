#include<iostream>
using namespace std;
inline int add(int a, int b) {
	return (a + b);
}
inline int sub(int a, int b) {
	return (a - b);
}
inline int mul(int a, int b) {
	return (a*b);
}
inline float divi(int a, int b) {
	float f;
	f= a / b;
	return f;
}
int main() {
	int a=50, b=10, c, d,e;
	float f;
	c = add(a, b);
	d = sub(a, b);
	e = mul(a, b);
	f = divi(a, b);
	cout << "a=" << a << endl;
	cout << "b=" <<b << endl;
	cout << "after addition:" << c << endl;
	cout << "after Subtraction:" << d << endl;
	cout << "after Multiplication:" << e <<endl;
	cout << "after division" << f << endl;
}