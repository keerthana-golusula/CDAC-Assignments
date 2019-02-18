#include<iostream>
using namespace std;
class queue {
	int r, f, size;
	int *q;
public:
	queue() {
		size = 0;
		r = f = -1;
		q = NULL;
	}
	queue(int x) {
		size = x;
		r = f = -1;
		q = new int[x];
	}
	void enque(int x) {
		if (r == -1 && f == -1) {
			f = 0;
			q[++r] = x;
		}else if()
	}

};