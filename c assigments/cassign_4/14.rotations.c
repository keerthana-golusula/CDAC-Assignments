#include<stdio.h>
#include<string.h>
int main(){
	int i,len,j;
	char str[50];
	printf("enter string\n");
	scanf("%s",str);
	len=strlen(str);
	for(i=0;i<len;i++){
		for(j=0;j<len;j++){
			printf("%c",str[(j+i)%len]);
		}
		printf("  ");
	}
	
	
}
