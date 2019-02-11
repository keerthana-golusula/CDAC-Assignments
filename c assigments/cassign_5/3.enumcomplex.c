#include<stdio.h>
struct complex{
	int r;
	int i;
};
enum op{
	add,sub,mul,div
};
int main(){
	int op;
	char *str[5];
	enum op ch;
	struct complex c1,c2,sum,diff,prod,divi;
	printf("enter the choice\n");
	printf("1.add\n2.sub\n3.mul\n4.div");
	scanf("%s",str);
	ch=str;
	switch(ch){
	case 1:
		printf("enter first complex number");
		scanf("%d%d",&c1.r,&c1.i);
		printf("enter second complex number");
		printf("%d%d",&c2.r,&c2.i);
		sum.i=c1.i+c2.i;
		sum.r=c1.r+c2.r;
		printf("sum is: %d +i %d",sum.r,sum.i);
		break;
    case 2:
    	printf("enter first complex number");
		scanf("%d%d",&c1.r,&c1.i);
		printf("enter second complex number");
		printf("%d%d",&c2.r,&c2.i);
		diff.i=c1.i-c2.i;
		diff.r=c1.r-c2.r;
		printf("sum is: %d +i %d",diff.r,diff.i);
		break;
	case 3:
			printf("enter first complex number");
		scanf("%d%d",&c1.r,&c1.i);
		printf("enter second complex number");
		printf("%d%d",&c2.r,&c2.i);
		prod.r = c1.r*c2.r - c1.i*c2.i;
      prod.i = c1.i*c2.r + c1.r*c2.i;
		break;
	case 4:
			break;
	case 5:
		break;
	default:
		printf("enter valid option\n");
			break;
		
	}
	
}
