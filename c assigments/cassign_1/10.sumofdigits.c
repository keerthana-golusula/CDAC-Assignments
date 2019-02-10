#include<stdio.h>
int main() {
	int num, n, sum = 0, r = 0;
	scanf("%d", &num);
	n = num;
	while (n) {
		r = n % 10;
		sum = sum + r;
		n = n / 10;
	}
	printf("sum of digits is %d", sum);


}