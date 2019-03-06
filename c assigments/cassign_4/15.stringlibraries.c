#include<stdio.h>
#include<string.h>
void str_rev(char *);
void str_cpy(char *,char *);
int str_cmp(char *,char *);
void str_cat(char *,char *);
int main(){
	char str[50],str2[50];
   printf_s("enter the string\n");
   scanf_s("%[^\n]s",str);// string input can contain spaces
   str_cpy(str2,str);//copy of str into str2
   printf_s("its copied into other string str2 is %s\n",str2);
   str_rev(str);//reversal of str
   printf_s("after reversal: %s\n",str);
   printf_s("concatinating string and its reversal\n");
  str_cat(str2,str);// concatination of str with str2
  printf("after concatenation: %s\n",str2);
}
//reversal of string into the same string

void str_rev(char * str){
	int i,j;
	char temp;
	for(i=0,j=strlen(str)-1;i<j;i++,j--){
		temp=str[i];
		str[i]=str[j];
		str[j]=temp;
	}
}
// concatination of string 2 with string 1
void str_cat(char *str1,char *str2){
	int i=0,j=0;
	i = strlen(str1);
	while(j<strlen(str2)){
		str1[i] = str2[j];
		i++;
		j++;
	}
	str1[i] = '\0';
	
}
// string comparing like in dictionary.
int str_cmp(char *str1,char *str2){
	int i=0,j=0;
	while(str1[i]==str2[i]){
		if(str1[i]=='\n'){
			return 0;
		}
		++i;
	if(str1[i]-str2[i]>0)
       return -1;
       else
       return 1;
   }
}

//copying string from char to char
void str_cpy(char *str2,char *str1){
	
	int i=0;
	while(i<strlen(str1))
	{
		str2[i] = str1[i];
		i++;
	}
	str2[i] = '\0';
}
