#include<stdio.h>
int isprime(int);
int main(){
   int a,b,i=0;
   scanf("%d%d",&a,&b);
   printf("%d",a);
   for(i=a;i<=b;i++){
   	if(isprime(i)==0){
   		printf("%d ",i);
	   }
   }

	
}
int isprime(int x){
	int f=0,i=0;
	if(x==2)
	return 0;
for(i=2;i<=x/2;i++){
	if(x%i==0){
		f=1;
	break;
}
}
if(f==0)
return 0;
return 1;
}
