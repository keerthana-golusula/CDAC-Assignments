#include<stdio.h>
#include<math.h>
int main(){
	int amt=500000,i;
	double ci,cih,ciq,si;
	scanf("%d",&i);
	si=amt+(amt*i*0.1);
	printf("simple interest: %lf",si);
	ci=amt*(pow((1+i*0.01),10));
	printf("compound interest anually: %lf",ci);
	cih=amt*(pow((1+i*0.005),20));
	printf("compund interest half yearly: %lf",cih);
	ciq=amt*(pow((1+i*0.0025),40));
	printf("compound interest quarterly: %lf",ciq);
	
	
	
	
}
