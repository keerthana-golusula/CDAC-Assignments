#include<stdio.h>
int threeon(num) {
	int i=0,sum= 0;
	while (i <= 3) {
		sum = sum + ((num >> i)&(0x0001));
		i++;
		//printf("%d\n", sum);
	}
	return sum;
}
