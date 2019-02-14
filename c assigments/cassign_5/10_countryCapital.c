#include<stdio.h>
#include<string.h>
int main() {
	int i;
	char c, ch;
	char str[190][30];
	FILE *fp;
	fopen_s(&fp, "countrycapital.txt", "w+");
	printf("Enter counties and capitals in country:capital format\n");
	i = 0;
	
	do {
		scanf_s("%c", &c);
		if (c == 'y') {
			scanf("%s", str[i]);
			//printf("test1");
			fputs(str[i], fp);
			//printf("test2");
			i++;
		}
		else {
			break;
		}
		printf("if you want to enter, press y");
		//printf("test3");
		//scanf_s("%c", &c);
		//printf("test3");
	}while(1);
	rewind(fp);
	while ((ch = fgetc(fp)) != EOF) {
		printf("%c", ch);
	}

	fclose(fp);
	system("pause");


}