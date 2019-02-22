#include<iostream>
using namespace std;
void bubbleSort(int *a, int n) {
	for (int i = 0; i < n - 1; i++) {
		int f = 0;
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1])
			{
				f = 1;
				swap(a[j], a[j + 1]);
			}
		}
		if (f == 0)
			break;
	}

}
 

int main() {
	int n;
	cout << "enter the size of array";
	cin >> n;
	int *a;
	a = new int[n];
	cout << "enter array elements" << endl;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	bubbleSort(a,n);
	cout << "array elements after sorting:" <<endl;
	for(int i=0;i<n;i++)
	cout << a[i] << " ";
	delete a;
}