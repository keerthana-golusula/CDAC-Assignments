#include<stdio.h>
#include<string.h>
int reverse(char *, int, int);
int main() {
	char str[50];
	scanf("%s", str);
	reverse(str, 0, strlen(str) - 1);
	printf("reverse of string is %s", str);
	return 0;
}
int reverse(char * str, int l, int h) {
	char temp;
	if (l > h)
		return 0;
	temp = str[l];
	str[l] = str[h];
	str[h] = temp;
	reverse(str, l + 1, h - 1);
	return 0;
}