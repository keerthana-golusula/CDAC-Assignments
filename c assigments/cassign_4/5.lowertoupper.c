#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main() {
	int i;
	char str[30];
	//scanf("%[^\n]s", str);
	gets(str);
	puts(str);
	for (i = 0; i < strlen(str); i++) {
		if (str[i] >= 97 && str[i] <= 122) {
			str[i] = str[i] - 32;
		}
		else if (str[i] >= 65 && str[i] <= 90) {
			str[i] = str[i] + 32;
		}
	}
		printf("%s", str);



}