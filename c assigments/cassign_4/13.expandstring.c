#include<stdio.h>
#include<string.h>
void deletec(char *,int);
void add(char *,int,char);
int main(){
	int i,k;
	char a,b;
	char str[50];
	printf("enter the input string\n");
	scanf("%[^\n]s",str);
	
//	add(str,2,ch);
	for(i=0;i<strlen(str);i++){
		if(str[i]=='-'){
			k=i;
		if(str[k-1]<str[k+1]){
			a=str[k-1];
			b=str[k+1]-1;
			deletec(str,k);
			//ch=str[k-1];
			while(a<b){
				add(str,k,b);
				b=b-1;
			}
	}
		}
	}	
printf("%s",str);
}
void add(char *str,int k,char ch){
	int t=strlen(str)+1;
	while(t!=k){
		str[t]=str[t-1];
		t--;	
	}
	str[t]=ch;
}

void deletec(char *str,int k){
int	len = strlen(str);
			while (k<(len-1)) {
				str[k] = str[k + 1];
				k++;
			}
	str[k] = '\0';
}
