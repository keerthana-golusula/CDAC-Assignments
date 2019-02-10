#include<stdio.h>
#include<string.h>
void str_rev(char *);
void str_cpy(char *,char *);
int str_cmp(char *,char *);
void str_cat(char *,char *);
int main(){
	char str[50],str2[50];
   printf("enter the string\n");
   scanf("%[^\n]s",str);	
   str_cpy(str2,str);
   printf("its copied into other string str2 is %s\n",str2);
   strrev(str);
   printf("after reversal: %s",str);
   printf("concatinating string and its reversal\n");
  str_cat(str2,str);
  printf("after concatenation: %s\n",str2);
}
void str_rev(char * str){
	int i,j;
	char temp;
	for(i=0,j=strlen(str)-1;i<j;i++,j--){
		temp=str[i];
		str[i]=str[j];
		str[j]=temp;
	}
}
void str_cat(char *str1,char *str2){
	int i=0,j=0;
	while(str1[i]!='\0')
	i++;
	while((str1[i]=str2[j])!='\0'){
		i++;
		j++;
	}
	
}
int str_cmp(char *str1,char *str2){
	int i,j;
	while(str1[i]==str2[i]){
		if(str1[i]=='\0'){
			return 0;
		}
		++i;
	if(str1[i]-str2[i]>0)
       return -1;
       else
       return 1;
   }
}
void str_cpy(char *str2,char *str1){
	int i;
	while((str2[i]=str1[i])!='\0')
	{
		i++;
	}
}
