#include<stdio.h>
#include<string.h>
void deletec(char *,int);
void add(char *,int,char);

int main(){
	int i,k;
	char before,after;
	char str[50];
	//char *str;
	printf("enter the input string\n");
	scanf("%[^\n]s",str);//input from string
	
	for(i=0;i<strlen(str);i++){
		if(str[i]=='-'){
			k=i;
			if (str[i - 1] >= 65 && str[i - 1] <= 90) {   // A-Z
				if (str[i + 1] > 90 || str[i + 1] < str[i - 1])
					continue;
			}
			else if (str[i - 1] >= 97 && str[i - 1] <= 122) {    //a-z
				if (str[i + 1] > 122 || str[i + 1] < str[i - 1])
					continue;
			}
			else if (str[i - 1] >= 48 && str[i - 1] <= 57) {    // 0-9
				if (str[i + 1] > 57 || str[i + 1] < str[i - 1])
					continue;
			}
			else {
			//after - , any special character just increment it.
				i++;
				continue;
			}
		//if(str[k-1]<str[k+1]){
			before=str[k-1];
			after=str[k+1]-1;
			deletec(str,k);//deletion of character '-'
			
			while(before<after){
				add(str,k,after);// additon of character in between a and b
				after=after-1;
			}
	//}
		}
	}	
	printf("After exapanding, the string is ");
printf("%s",str);
}
// addition of character into string
void add(char *str,int k,char ch){
	int temp=strlen(str)+1;
	while(temp!=k){
		str[temp]=str[temp-1];
		temp--;	
	}
	str[temp]=ch;
}
//deletion of character from the string
void deletec(char *str,int k){
int	len = strlen(str);
			while (k<(len-1)) {
				str[k] = str[k + 1];
				k++;
			}
	str[k] = '\0';
}
