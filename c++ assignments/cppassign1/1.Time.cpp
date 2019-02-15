#include<iostream>
using namespace std;
class Time {
	int hr, min, sec;
public:
	Time() {
		hr = 0;
		min = 0;
		sec = 0;
	}
	Time(int h, int m, int s) {
		hr = h;
		min = m;
		sec = s;
	}
	void display() {
		cout << hr << ":" << min << ":" << sec << endl;
	}
	Time add(Time t) {
		Time temp;
		temp.sec = sec + t.sec;
		temp.min = min + t.min;
		temp.hr = hr + t.hr;
		if (temp.sec >= 60) {
			temp.min++;
			temp.sec =temp.sec-60;
		}
		if (temp.min >= 60) {
			temp.hr++;
			temp.min = temp.min-60;
		}
		return temp;
	 }
};
int main() {
	Time t1(5, 32, 55), t2(10, 30, 25),t3;
	t3 = t1.add(t2);
	t3.display();
}