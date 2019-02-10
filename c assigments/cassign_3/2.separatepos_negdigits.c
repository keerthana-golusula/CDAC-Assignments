#include<stdio.h>
int main() {
	int arr[] = { -12, 11, -13, -5, 6, -7, 5, -3, -6 };
	int i, k, j;
	for (i = 0; i < 9; i++) {
		if (i==0&&arr[i]<0){
			continue;
		}
		else if (arr[i] <0) {
			k = arr[i];
			j = i - 1;
			while (arr[j] > 0) {
				arr[j+1] = arr[j];
				j--;
			}
			arr[j + 1] = k;
		}

	   }
	for (i = 0; i < 9; i++) {
		printf("%d ", arr[i]);
	}



}