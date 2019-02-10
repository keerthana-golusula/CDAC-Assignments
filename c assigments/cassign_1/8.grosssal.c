#include<stdio.h>
int main(){
	int sal,gsal;
	scanf("%d",&sal);
	if(sal<1){
		printf("enter valid salary");
	}else if(sal<=4000){
		gsal=sal+sal*0.1+0.5*sal;
	}else if(sal<8000){
		gsal=sal+sal*.2+sal*.6;
	}else if(sal<12000){
		gsal=sal+sal*0.25 +sal*0.7;
	}else{
		gsal=sal+sal*.3+sal*.8;
	}
	printf("gross salary of given salary %d is %d",sal,gsal);
	
}

