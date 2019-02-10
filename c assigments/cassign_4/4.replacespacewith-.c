#include<stdio.h>
int main() {
	char *cat = "The cat sat";
	int n = replace(cat);
	printf("after replacing string is %s\n", cat);
	printf("no of replaces done is %d", n);
	return 0;
}
int replace(char * str) {
	int i = 0,count=0;
	for (i = 0; i < strlen(str); i++) {
		if (str[i] == ' ') {
			str[i] = '-';
			count++;
		}
	}
	return count;
}