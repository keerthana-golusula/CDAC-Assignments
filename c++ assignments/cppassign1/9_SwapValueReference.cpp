#include<iostream>
using namespace std;
void swapByValue(int a, int b) {
	a = a + b;
	b = a - b;
	a = a - b;
}
void swapByReference(int &x, int &y) {
	x = x + y;
	y = x - y;
	x = x - y;
}
int main() {
	int a,b,op;
	cin >> a >> b;
	cout << "choose the choice:" << endl;
	cout << "1.swapByValue" << endl;
	cout << "2.swapByreferrence" << endl;
	cin >> op;
	switch (op) {
	case 1:
		swapByValue(a, b);
		cout << "After swappd By value: a=" << a << " b=" << b << endl;
		break;
	case 2:
		swapByReference(a, b);
		cout << "After swappped by reference: a= " << a << " b=" << b << endl;
		break;
	default:
		cout << "enter valid option";
		break;


	}



}
