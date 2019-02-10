#include<stdio.h>
int main() {
	int num = 31,count=0,rem=0;
	printf("enter anumber which is 8 bit number,that is less than 256");
	scanf("%d", &num);
	if (num > 255)
	{
		printf("larger than 8 bit integer");
		return -1;
	}
	while (num) {
		rem = num % 2;
		if (rem == 1) {
			count++;
		}
		num = num / 2;

	}
	printf("number of bits that are set are %d", count);


}