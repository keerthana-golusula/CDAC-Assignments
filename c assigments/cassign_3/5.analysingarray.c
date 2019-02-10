#include<stdio.h>
int main() {
	int x[8] = { 10,20,30,40,50,60,70,80 };
	printf("meaning of x is: %d\n",x);
	// referrence of 0th element of array x
	printf("meaning of (x+2) is %d\n", x + 2);
	// reference to the 2th element of array x
	printf("meaning of *x is %d\n", *x);
	// value in the 0th element
	printf("meaning of (*x+2) is %d\n", (*x + 2));
	// addition of scalar 2 to the value at 0th element
	printf("meaning of *(x+2) is %d\n", *(x + 2));
	// value at the 2 th elemnt in th array x


}