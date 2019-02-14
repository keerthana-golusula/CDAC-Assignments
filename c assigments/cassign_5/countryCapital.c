#include<stdio.h>
#include<string.h>
int main() {
	int i;
	char c,ch;
	char str[190][30];
	FILE *fp;
	fopen_s(&fp, "countrycapital.txt", "w+");
	printf("Enter counties and capitals in country:capital format\n");
	i = 0;
	scanf("%c", &c);
	while (1) {
		if (c == 'y') {
			scanf("%[^\n]s", str[i]);
			fputs(str[i], fp);
			i++;
		}else{
			break;
		}
		printf("if you want to enter, press y");
		scanf("%c", &c);
}
	rewind(fp);
	while ((ch = fgetc(fp)) != EOF) {
		printf("%c", ch);
	}

	fclose(fp);
	system("pause");


}