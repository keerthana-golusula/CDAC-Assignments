#include<stdio.h>
void replaceTabs() {
	printf("Hello");
	char ch, c;
	char * str;
	str = "\t";
	FILE *fp = NULL;
	// opening a file
	fopen_s(&fp, "file2.txt", "a+");
	// if file opens with out any error
	if (fp != NULL) {
		while ((ch = fgetc(fp)) != '\0') {
			if (ch == '\t') {
				fprintf(fp, "%s", str);
				//fputs(str,fp);
				//fputc('t', fp);
				delete_char(fp);
				//delete_char(fp);
				//delete_char(fp);
				//delete_char(fp);
			}

		}
		fclose(fp);
	}
	// file open failed printing error message
	else {
		printf("opening file failed");
	}
}