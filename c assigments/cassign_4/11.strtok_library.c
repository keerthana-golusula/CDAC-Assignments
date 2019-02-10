#include<stdio.h>
#include<string.h>
void strtoken(char *, const char);
int main() {
	char str[50];
	const char del = ',';
	printf("enter string");
	scanf("%[^\n]s", str);
	printf("tokens are\n");
	strtoken(str, del);

}
void strtoken(char * str, const char del) {
	int i=0;
 for(i=0;i<strlen(str);i++){
 	if(str[i]==del)
 	printf(" ");
 	else
 	printf("%c",str[i]);
 }

}
