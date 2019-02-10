#include<stdio.h>
int main(){
	int num,n, r=0,sum=0;
	scanf("%d", &num);
	n = num;
	while (n) {
		r = n % 10;
		sum = sum + (r*r*r);
		n = n / 10;
	}
	if (sum == num)
		printf("given number is armstrong number");
	else
		printf("given number is not an armstrong number");

}