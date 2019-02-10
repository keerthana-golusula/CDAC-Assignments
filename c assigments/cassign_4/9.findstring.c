#include<stdio.h>
#include<string.h>
int main(){
	int i,k,t,f=0;
	char str[50];
	char s[10];
	printf("enter the string\n");
	scanf("%[^\n]s",str);
	printf("enter the string you want to search for\n");
	scanf("%s",s);
	
	for(i=0;i<strlen(str);i++){
		k=0;
		//t=i;
		if(str[i]==s[0]){
		  t=i;
		  k=0;
			while(str[t]==s[k]){
				if(t==strlen(str))
				break;
				t++;
				k++;
			}
			if(k==strlen(s)){
				f=1;
				printf("string is matched at index %d",i);
				return 0;
			}
		}
	}
	if(f==0){
		printf("string 2 is not present in string one"); 
	}
	return 0;
	
}
