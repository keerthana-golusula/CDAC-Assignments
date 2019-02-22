#include<iostream>
using namespace std;
void swap(int &a, int &b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}
void buildHeap(int *a, int i, int n) {
	int temp, c;
	temp = a[i];
	for (; 2*i < n - 1; i = c) {
		c = 2 * i + 1;
		if (c + 1 < n && a[c + 1] > a[c])
			c++;
		if (a[c] > temp)
			a[i] = a[c];
		else
			break;


	}
	a[i] = temp;

}
void heapSort(int *a,int n) {
	for (int i = n / 2 - 1; i >= 0; i--)
		buildHeap(a, i, n);
	for (int j = 1; j <= n - 1; j++) {
		swap(a[0], a[n - j]);
		buildHeap(a, 0, n - j);
	}

}

int main(){
int n;
cout << "enter the size of array" << endl;
cin >> n;
cout << "enter array elements" << endl;
int *a;
a = new int[n];
for (int i = 0; i < n; i++)
	cin >> a[i];
heapSort(a,n);
cout << "enter sorting:" << endl;
for (int i = 0; i < n; i++) {
	cout << a[i] << " ";
}


delete a;
}