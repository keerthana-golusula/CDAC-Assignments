#include<stdio.h>
struct complex{
	int r;
	int i;
};
enum op{
	add,sub,mul,div,exi
};
int main(){
	int op,x,y,z;
	char *str[5];
	enum op ch;
	struct complex c1,c2,sum,diff,prod,divi;
	while (1) {
		printf("enter the choice\n");
		printf("0.add\n1.sub\n2.mul\n3.div\n4.exit\n");
		scanf("%d", &op);
		ch = op;
		switch (ch) {
		case add:
			printf("enter first complex number");
			scanf("%d%d", &c1.r, &c1.i);
			printf("enter second complex number");
			scanf("%d%d", &c2.r, &c2.i);
			sum.i = c1.i + c2.i;
			sum.r = c1.r + c2.r;
			printf("sum is: %d +i %d", sum.r, sum.i);
			break;
		case sub:
			printf("enter first complex number");
			scanf("%d%d", &c1.r, &c1.i);
			printf("enter second complex number");
			scanf("%d%d", &c2.r, &c2.i);
			diff.i = c1.i - c2.i;
			diff.r = c1.r - c2.r;
			printf("difference is: %d +i %d", diff.r, diff.i);
			break;
		case mul:
			printf("enter first complex number");
			scanf("%d%d", &c1.r, &c1.i);
			printf("enter second complex number");
			scanf("%d%d", &c2.r, &c2.i);
			prod.r = c1.r*c2.r - c1.i*c2.i;
			prod.i = c1.i*c2.r + c1.r*c2.i;
			printf("product is %d +i%d", prod.r, prod.i);
			break;
		case div:
			printf("enter first complex number");
			scanf("%d%d", &c1.r, &c1.i);
			printf("enter second complex number");
			scanf("%d%d", &c2.r, &c2.i);

			if (c2.r != 0 && c2.i != 0)
			{
				z = c2.r*c2.r + c2.i*c2.i;
				x = c1.r*c2.r + c1.i*c2.i;
				y = c1.i*c2.r - c1.i*c2.r;
				divi.r = x / z;
				divi.i = y / z;
			}
			else if (c2.r == 0 && c2.i != 0) {
				divi.r = c1.i / c2.i;
				divi.i = -c1.r / c2.i;
			}
			else if (c2.r != 0 && c2.i == 0) {
				divi.r = c1.r / c2.r;
				divi.i = c1.i / c2.r;
			}
			else {
				printf("division not possible");
				break;
			}
			printf("division is %d +i%d", divi.r, divi.i);
			break;
		case exi:
	//		break;
			exit(0);
			//system("pause");
		default:
			printf("enter valid option\n");
			break;

		}
	}
}
