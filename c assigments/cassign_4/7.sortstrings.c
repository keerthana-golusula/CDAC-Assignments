#include<stdio.h>
int main(){
	int n,i,j,small;
	char(*str)[20];
	scanf("%d", &n);
	str = (char(*)[20]) malloc(n * 20);
	for (i = 0; i < n; i++) {
		scanf("%s", str[i]);
	}
	char temp[20];
	//char str[50][20];
	printf("enter no of strings\n");
	for (i = 0; i < n; i++) {
		//temp = str[i];
		small = i;
		for (j = i + 1; j < n; j++) {
			if (strcmp(str[i], str[j]) > 0)
				small = j;
		}
		strcpy(temp, str[i]);
		strcpy(str[i], str[small]);
		strcpy(str[small], temp);
	 }
	for (i = 0; i < n; i++) {
		printf("%s", str[i]);
	}
	free(str);
	//printf("%s", str[0]); 

	system("pause");
	return 0;

}
