#include<stdio.h> 
// countchars function definition
void countchars() {
	int spaces = 0, alphabets = 0, digits = 0, special = 0;
	FILE *fp = NULL;
	char ch = 'a';
	// opening a file
	fp = fopen_s(&fp, "file2.txt", "a+");
	// if file open succeeds
	if (fp != NULL) {
		while ((ch = fgetc(fp)) != '\0')
		{
			if (ch == ' ')
				spaces++;
			else if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122))
				alphabets++;
			else if (ch >= 48 && ch <= 57)
				digits++;
			else
				special++;
		}
		//printf("%c", ch);
		printf("no.of alphabets are %d\n", alphabets);
		printf("no.of digits are %d\n", digits);
		printf("no.of spaces are %d\n", spaces);
		printf("no.of special characters are %d\n", special);


		fclose(fp);
	}
	// file not opened printing error message
	else {
		printf("file not opened successfully");
	}
}