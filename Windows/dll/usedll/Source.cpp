#include<stdio.h>
#include<windows.h>
#include "dll.h"
int main() {
	int a = 20, b = 10;
	printf("sum of two numbers is %d",add(a, b));
	printf("difference of two given numbers is %d", sub(a, b));
	system("pause");
	return 0;
}