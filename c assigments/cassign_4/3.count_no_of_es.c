#include<stdio.h>
int main() {
	char * s[] = {
		"we will teach you how to ",
	"Move a mountain ",
	"Level a building ",
	"Erase the past ",
	"Make a million " };
	int len,i,j,count=0;
	len = sizeof(s) / sizeof(s[0]);
	//printf("%d", len);
	//printf("%s", s[1]);

for (i = 0; i < len; i++) {
		for (j = 0; j < strlen(s[i]); j++) {
			if (s[i][j] == 'e')
				count++;
		}

	}
	printf("%d", count);
}