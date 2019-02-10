#include<stdio.h>
int main(){
	int num,n,rev=0,rem=0;
	scanf("%d",&n);
	num=n;
	while(num){
		rem=num%10;
		rev=rev*10+rem;
		num=num/10;
	}
	printf("reverse of %d is %d",n,rev);
}
