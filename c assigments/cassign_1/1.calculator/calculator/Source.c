#include <stdio.h>

#include <stdlib.h>

int a, b, o, res;

int sub(int x, int y);


int mul(int x, int y);

int add(int x, int y);

int divi(int x, int y);
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {		
		while(1) {
			printf("choose your option:\n");
			printf_s("enter 1 to add\n enter 2 to sub\n enter 3 to mul\n enter 4 for div\n5 for exit");

			scanf_s("%d", &o);

			printf_s("enter first operand\n");

			scanf_s("%d", &a);

			printf_s("enter second operand\n");

			scanf_s("%d", &b);

			switch (o) {

			case 1:

				res = add(a, b);

				//res=a+b;

				break;

			case 2:

				res = sub(a, b);

				//res=a-b;

				break;

			case 3:

				res = mul(a, b);

				//res=a*b;

				break;

			case 4:

				res = divi(a, b);

				//res=a/b;

				break;
			case 5:
				exit(0);
			default:

				break;

			}

			printf_s("%d", res);

		}
	
	system("pause");
	return 0;



}