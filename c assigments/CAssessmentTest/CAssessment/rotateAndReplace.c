#include<stdio.h>
void rotateAndReplace() {
	char str[50], str2[50];
	char ch;
	int i;
	//opening a file
	FILE *fp = NULL;
	FILE *fp2;
	fopen_s(&fp, "file2.txt", "a+");
	// if file opened successfully
	if (fp != NULL) {
		printf("enter the string\n");
		scanf_s("%s", str);
		strcpy_s(str2, strlen(str), str);
		printf("%s", str2);
		//strrev(str);
		while ((ch = fgetc(fp)) != EOF) {
			if (ch == str2[0]) {
				i = 0;
				//while (i <= strlen(str)) {
				fp2 = fp;
				while (((ch = fgetc(fp2)) == str2[i]) && str2[i] != '\0')
					//fputc(str[i], fp);
					//f = 1;
					//break;
					i++;
			}
			if (i == strlen(str2)) {
				fp2 = fp;
				//fseek(fp2, -(strlen(str)), SEEK_CUR);
				while ((ch = fgetc(fp2)) == str2[i])
					fputc(str[i], fp);
				i++;
			}

			fclose(fp);
		}
	}
	else { // if file open fails printing a message
		printf("file open failed");
	}
}
