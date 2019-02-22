#include<iostream>
using namespace std;
void selectionSort(int *a, int n) {
	for (int i = 0; i < n - 1; i++) {
		int small = i;
		for (int j = i + 1; j < n; j++) {
			if (a[small] > a[j])
				small = j;
		}
		if (small != i)
			swap(a[i], a[small]);

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
     selectionSort(a, n);
	cout << "enter sorting:" << endl;
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}

	delete a;



}