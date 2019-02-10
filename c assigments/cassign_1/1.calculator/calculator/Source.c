#include <stdio.h>

#include <stdlib.h>

int a, b, o, res;

int sub(int x, int y);
/*{

	int temp = x - y;

	return temp;

}*/

int mul(int x, int y);/*

	int temp = x*y;

	return temp;

}*/

int add(int x, int y);/*

	int temp = x + y;

	return temp;

}*/

int divi(int x, int y);/*

	int temp = x / y;

	return temp;

}*/

/* run this program using the console pauser or add your own getch, system("pause") or input loop */



int main(int argc, char *argv[]) {

	while (1) {

		char c;

		printf_s("do you want to perform arithmatic operation if yes enter y and if not enter n");

		scanf_s("%c",&c);

		if (c == 'y') {

			printf_s("enter 1 to add\n enter 2 to sub\n enter 3 to mul\n enter 4 for div\n");

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

			default:

				break;

			}

			printf_s("%d", res);

		}
		else {

			break;

		}

	}
	int x;
	scanf_s("%d", &x);
	return 0;



}