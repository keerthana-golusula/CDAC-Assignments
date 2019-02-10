#include<stdio.h>
int main()
{
	int num,n,rev=0,rem=0;
	scanf("%d", &num);
	n = num;
	while (n) {
		rem = n % 10;
		rev = rev * 10 + rem;
		n = n / 10;
	}
	if (rev == num) 
		printf("given number is palindrome");
	else 
		printf("given number is not a palindrome");
	int x;
	scanf("%d", &x);

	return 0;
}