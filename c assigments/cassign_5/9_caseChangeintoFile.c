#include<stdio.h>
int main() {
	int i, len;
	FILE *fp=NULL;
	char str[100];
	fopen_s(&fp, "newfile.txt", "w+");
	printf("enter line of characters\n");
	scanf("%[^\n]s", str);
	len = strlen(str);
	printf("%d", len);
	i = 0;
	//fputc('a', fp);
	while (i < len) {
		if (str[i] >= 97 && str[i] <= 122)
			str[i] = str[i] - 32;
		else if (str[i] >= 65 && str[i] <= 90)
			str[i] = str[i] + 32;
		else
		{ }
	
	fputc(str[i], fp);
		i++;
	}
	fclose(fp);
	return 0;
}