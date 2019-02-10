#include<stdio.h>
int main(){
	int num,sum=0,k,rem;
	scanf("%d",&num);
	k=1;
	while(num){
		//printf("hello");
		rem=num%2;
		sum=sum+rem*k;
		num=num/2;
		k=k*10;
	}
	printf("binary digit is : %.5d",sum);
	
	return 0;
}
