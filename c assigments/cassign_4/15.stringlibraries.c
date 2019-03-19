#include<stdio.h>
#include<string.h>
void str_rev(char *);
void str_cpy(char *,char *);
int str_cmp(char *,char *);
void str_cat(char *,char *);
int main(){
	char string1[50],string2[50],string3[50];
   printf_s("enter the string\n");
   scanf_s("%[^\n]s",string1);// string string can contain spaces
     scanf_s("%[^\n]s",string3);
   str_cpy(string2,string1);//copy of str into str2
   printf_s("its copied into other string string2 is %s\n",string2);
   str_rev(string1);//reversal of str
   printf_s("after reversal: %s\n",string1);
   printf_s("concatinating string and its reversal\n");
  str_cat(string2,string1);// concatination of str with str2
  printf("after concatenation: %s\n",string2);
  printf("enter string to be compared with string1:");
  //scanf_s("%[^\n]s",string3);
  getchar();
  if(str_cmp(string3,string1)<0){
  	printf("string3 is less than string1");
  }else if(str_cmp(string3,string1)>0){
  	printf("string3 is greater than string1");
  }else{
  	printf("string3 is equal to string1");
  }
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
       return 1;
       else
       return -1;
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
