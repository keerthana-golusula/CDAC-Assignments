#include<stdio.h>
#include<string.h>
void delete(char *,char,int);
int main(){
	int i,j;
	char str[50], s[10];
	printf("enter the string \n");
	scanf("%[^\n]s",str);
	printf("enter the string from which characters are taken to remove\n");
	scanf("%s",s);
	for(i=0;i<strlen(str);i++){
		for(j=0;j<strlen(s);j++){
			if(str[i]==s[j]){
				delete(str,s[j],i);
				i=i-1;
				break;
		}
	}
	}
	printf("%s",str);
	
	
}
void delete(char *str,char ch,int k){
int	len = strlen(str);
			while (k<(len-1)) {
				str[k] = str[k + 1];
				k++;
			}
	str[k] = '\0';
}
