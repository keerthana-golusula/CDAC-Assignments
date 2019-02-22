#include<iostream>
using namespace std;
void swap(int &a, int &b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}
void quickSort(int *a, int low, int high) {
	int i, j;
	i = low + 1;
	j = high;
	int pivot = a[low];
	if (low < high) {
		while (1) {
			while (i <= high&&a[i] < pivot)
				i++;
			while (a[j] > pivot)
				j--;
			if (i < j)
				swap(a[i], a[j]);
			else
				break;
		}
		swap(a[low], a[j]);
		quickSort(a, low, j - 1);
		quickSort(a, j + 1,high);

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
	quickSort(a, 0, n - 1);
	cout << "enter sorting:" << endl;
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}

	delete a;
	
}

