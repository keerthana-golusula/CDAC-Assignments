// string library functions definition
#include<stdio.h>
#include<string.h>
void str_rev(char *);
void str_cpy(char *,char *);
int str_cmp(char *,char *);
void str_cat(char *,char *);

int main(){
<<<<<<< HEAD
	char str[50],str2[50],str3[50],str4[50];
=======
	char string1[50],string2[50],string3[50];
>>>>>>> f4724911e51bcc0ad02cbf157b1853c591e81da3
   printf_s("enter the string\n");
   scanf_s("%[^\n]s",string1);// string string can contain spaces
     scanf_s("%[^\n]s",string3);
   str_cpy(string2,string1);//copy of str into str2
   printf_s("its copied into other string string2 is %s\n",string2);
   str_rev(string1);//reversal of str
   printf_s("after reversal: %s\n",string1);
   printf_s("concatinating string and its reversal\n");
<<<<<<< HEAD
  str_cat(str2,str);// concatination of str with str2
  printf("after concatenation: %s\n",str2);
  printf("enter two strings to  compare\n");
  scanf_s("%s", str3);
  scanf_s("%s", str4);
  if (str_cmp(str3, str4) > 0) {
	  printf("%s is greater than %s\n", str3, str4);
  }
  else if (str_cmp(str3, str4) < 0)
	  printf("%s is less than %s\n", str3, str4);
  else
	  printf("%s is equal to %s\n", str3, str4);
  system("pause");
=======
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
>>>>>>> f4724911e51bcc0ad02cbf157b1853c591e81da3
}

//reversal of string into the same string: swapping of chararacters till middle
void str_rev(char * str){
	int i,j;
	char temp;
	for(i=0,j=strlen(str)-1;i<j;i++,j--){
		temp=str[i];
		str[i]=str[j];
		str[j]=temp;
	}
}

// concatination of string 2 with string 1: function takes two inputs , second string is added to first string at end
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

// string comparing like in dictionary.: function takes two strings as inputs, 
//returns -1 if string1 is less than string2
// returns 1 if string1 is greater than string1
// returns 0 if string 1 is equal to string2
int str_cmp(char *str1,char *str2){
	int i=0,j=0;
	while (str1[i] == str2[i]) {
		if (str1[i] == '\n') {
			return 0;
		}
		++i;
<<<<<<< HEAD
	}
		if(str1[i]-str2[i]>0)
       return 1;
       else
       return -1;
   
=======
	if(str1[i]-str2[i]>0)
       return 1;
       else
       return -1;
   }
>>>>>>> f4724911e51bcc0ad02cbf157b1853c591e81da3
}

//copying string from char to char: function takes two strings as input: contents of string2 is copied to string1
void str_cpy(char *str2,char *str1){
	
	int i=0;
	while(i<strlen(str1))
	{
		str2[i] = str1[i];
		i++;
	}
	str2[i] = '\0';
}
