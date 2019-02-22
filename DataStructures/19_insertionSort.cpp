#include<iostream>
using namespace std;
void insertionSort(int *a, int n) {
	int j, temp;
	for (int i = 1; i < n; i++) {
		temp = a[i];
		for (j = i-1; j > 0; j--) {
			if (temp < a[j])
				a[j + 1] = a[j];
		}
		a[j + 1] = temp;


	}
}
int main() {
	int n;
	cout << "enter the size of array" << endl;
	cin >> n;
	cout << "enter array elements" << endl;
	int *a;
	a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	insertionSort(a, n);
	cout << "enter sorting:" << endl;
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}

	delete a;
}
