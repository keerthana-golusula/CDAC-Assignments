#include<iostream>
using namespace std;
class Point {
	int x;
	int y;
public:
	Point() {
		x = y = 0;
	}
	Point(int a, int b) {
		x = a;
		y = b;
	}
	double distance(Point p) {
		double temp;
		temp = sqrt(((p.x - x)*(p.x - x)) + ((p.y - y)*(p.y - y)));
		return temp;
	}
	void display() {
		cout << "("<<x << "," << y <<")"<< endl;
	}
};
int main() {
	Point p1(3, 4), p2(6, 8);
	double d=p1.distance(p2);
	cout << d << endl;
}