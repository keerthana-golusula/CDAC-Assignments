#include<stdio.h>
int factorial(int);
int main() {
	int num, fact = 1;
	scanf("%d", &num);
	fact = factorial(num);
	printf("factorial of number %d is %d", num, fact);

}
int factorial(int num) {
	if (num == 0 || num == 1)
		return 1;
	else
		return num*factorial(num - 1);
}