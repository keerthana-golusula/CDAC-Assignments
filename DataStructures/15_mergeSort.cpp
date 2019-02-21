#include<iostream>
using namespace std;
void merge(int *, int, int, int);
void mergeSort(int *a, int low, int high) {
	if (low < high)
	{
		int mid;
		mid = (low + high) / 2;
		mergeSort(a, low, mid);
		mergeSort(a, mid + 1, high);
		merge(a,low, mid, high);
	}

}
void merge(int *a,int l1s,int l1e,int l2e) {
	int l2s = l1e + 1;
	int *l3, i, j,k;
	l3 = new int[l2e - l1s + 1];
	i = l1s;
	j = l2s;
	k = 0;
	while (i <= l1e &&j <= l2e) {
		if (a[i] > a[j])
			l3[k++] = a[j++];
		else
			l3[k++] = a[i++];
	}
	while (i <= l1e)
		l3[k++] = a[i++];
	while (j <= l2e)
		l3[k++] = a[j++];
	for (int t = l1s; t <= l2e; t++)
		a[t] = l3[t - l1s];
	/*while (l2e >= l1s) {
		a[l2e--] = l3[--k];
		cout << a[l2e] << " ";
	}
	cout << endl;*/
	delete l3;

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
	mergeSort(a, 0, n-1);
	cout << "array elements after sorting:" << endl;
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}