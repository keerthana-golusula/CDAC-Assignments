#include<iostream>
using namespace std;
class distance2;
class distance1 {
	int m, cm;
public:
	distance1() {
		m = cm = 0;
	}
	distance1(int a, int b) {
		m = a;
		cm = b;
	}
	void display() {
		cout << m << "m," << cm << "cm" << endl;
	}
	friend distance1 add(distance1,distance2);
	friend distance2 add(distance2, distance1);
};
class distance2 {
int f, in;
public:
	distance2() {
		f = in = 0;
	}
	distance2(int a, int b) {
		f = a;
		in= b;
	}
	void display2() {
		cout << f << "feets," << in << "inches" << endl;
	}
	friend distance1 add(distance1 ,distance2);
	friend distance2 add(distance2, distance1);
};
distance1 add(distance1 d1, distance2 d2) {
	distance1 temp;
	temp.m = d1.m + (int)(d2.f*0.3048);
	temp.cm = d1.m + (int)(d2.in*2.54);
	if (temp.cm >= 100) {
		temp.m++;
		temp.cm = temp.cm - 100;
	}
	return temp;
}
distance2 add(distance2 d2, distance1 d1) {
	distance2 temp;
	temp.f = d2.f + (int)(d1.m*3.2808399);
	temp.in = d2.in + (int)(d1.cm*0.39370079);
	if (temp.in >= 12) {
		temp.f++;
		temp.in = temp.in - 12;
	}
	return temp;
}
int main() {
	distance1 di1(10,5),di3;
	distance2 di2(5, 10), di4;
	di3 = add(di1, di2);
	cout << "in meters and centimetrs:\n";
	di3.display();
	di4 = add(di2, di1);
	cout << "in feets and inches\n";
	di4.display2();

}