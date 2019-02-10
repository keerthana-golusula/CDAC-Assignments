#include<stdio.h>
int main() {
	int arr[100];
	int i = 0, sum = 0, min = 36555, max = 0, l = 0;
	float avg;
	while (1) {
		scanf("%d", &arr[i]);
		if (arr[i] <= 0) {
			break;
		}
		else {
			i++;
			l = i;
		}
	}
	for (i = 0; i <l; i++) {
		if (arr[i] < min)
			min = arr[i];
		if (arr[i] > max)
			max = arr[i];
		sum = sum + arr[i];
		
	}
	avg = (float)(sum / l);
	//g2 = sum / l;
	printf("minimum value is %d", min);
	printf("maximum value is %d", max);
	printf("average value is %f",avg);

}
