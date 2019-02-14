#include<stdio.h>
int main() {
	char ch;
	FILE *fp;
	fopen_s(&fp, "file.txt", "r+");
	if (fp != NULL) {
		printf("file opened\n");
		while (!feof(fp)) {
			ch = fgetc(fp);
			printf("%c", ch);
		}
	}
	else {
		printf("file doesnot opened");
	}

}