#include<stdio.h>
long int dectobin(int);
int main(){
	long int bin,res2;
	int dec,res1;
	printf("enter binary number ");
	scanf("%ld",&bin);
    res1=bintodec(bin);
	printf("decimal number is %d",res1);
	printf("enter decimal number");
	scanf("%d",&dec);
	res2=dectobin(dec);
	printf("binary number is %ld",res2);
	
}
int bintodec(int bin){
	
	int k=1,rem=0,dec=0;
	while(bin){
		rem=bin%10;
		dec=dec+rem*k;
		k=k*2;
		bin=bin/10;
	}
	return dec;
}
long int dectobin(int dec){
	long int bin=0;
	int rem=0,i=1;
	while(dec){
		rem=dec%2;
		dec/=2;
		bin+=rem*i;
		i=i*10;
	}
	return bin;
	
}
