#include<stdio.h>
#include<string.h>
int main() {
	int i;
	char c,ch;
	char str[190][30];
	FILE *fp;
	fopen_s(&fp, "countrycapital.txt", "w+");
	printf("Enter counties and capitals in country:capital format");
	i = 0;
	while (1) {
		printf("if you want to enter, press y");
		scanf("%c", &c);
		if (c == 'y') {
			scanf("%s", str[i]);
			fputs(str[i], fp);
			i++;
		}else{
			break;
		}
}
	rewind(fp);
	while ((ch = fgetc(fp)) != EOF) {
		printf("%c", c);
	}

	fclose(fp);
	system("pause");


}