#include<iostream>
using namespace std;
int main() {
	int n;
	cout << "enter the size of array";
	cin >> n;
	int a[n];
	cout << "enter array elements" << endl;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	bubbleSort(a,n);
	cout << "array elements after sorting:" <<endl;
	for(int i=0;i<n;i++)
	cout << a[i] << " ";

}