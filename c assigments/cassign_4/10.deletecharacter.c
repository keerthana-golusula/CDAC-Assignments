#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main() {
	int len, k, i;
	char str[20];
	char ch;

	printf("enter the string\n");
	scanf("%[^\n]s", str);
	printf("enter character to be deleted\n");
	
	scanf(" %c",&ch);
	len = strlen(str);
	for (i = 0; i < len; i++) {
		if (str[i] == ch) {
			
			k = i;
			while (k<(len-1)) {
				str[k] = str[k + 1];
				k++;
			}
			i = i - 1;
			len = len - 1;
			//printf("len");
		}

	}
	str[i] = '\0';
	printf("After removal of character %c is", ch);
	printf("%s", str);
	system("pause");
	return 0;

}