#include<stdio.h>
char delete_char(FILE *);
// removeComments function definition
void removeComments() {
	FILE *fp = NULL;
	char ch, ch2, c1, c2, c;
	//opening a file
	fopen_s(&fp, "file2.txt", "a+");
	// if file opens sucessfully
	if (fp != NULL) {
		printf("file opened successfully");
		while (!feof(fp)) {
			ch = fgetc(fp);
			ch2 = fgetc(fp);
			if (ch == '/') {
				if (ch2 == '/') {
					fseek(fp, -2, SEEK_CUR);
					while ((c = delete_char(fp)) == '\n');
				}
				else if (ch2 == '*') {
					fseek(fp, -2, SEEK_CUR);
					while ((c1 = delete_char(fp)) == '*' && (c2 = delete_char(fp)) == '/');
				}
			}
		}
		fseek(fp, -1, SEEK_CUR);
		fclose(fp);
	}
	// if file open fails
	else
	{
		printf("opening file failed");
	}
}
char delete_char(FILE *fp) {
	char ch;
	FILE *fp2 = NULL;
	ch = fgetc(fp);
	while (!feof(fp)) {
		fp2 = fseek(fp, -1, SEEK_CUR);
		fputc(fgetc(fp2), fp);
	}
	return ch;
}