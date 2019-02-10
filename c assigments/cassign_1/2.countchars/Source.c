#include<stdio.h>

int i, l, ls, bks, dgts, sp,tbs;

int main() {

	char str[80];

	printf_s("length of string <80");

	scanf_s("%d", &l);

	for (i = 0; i<l; i++) {

		scanf_s("%c", &str[i]);

	}

	for (i = 0; i<l; i++) {

		if (str[i]>47 && str[i]<58) {

			dgts++;

		}
		else if (str[i] == 9) {
			tbs++;
		}
		else if (str[i] == 32) {

			bks++;

		}
		else if ((str[i]>96 && str[i]<123) || (str[i]>64 && str[i]<91)) {

			ls++;

		}
		else {

			sp++;

		}

	}

	printf_s("no. of letters are %d\n", ls);

	printf_s("no. of digits are %d\n", dgts);
	printf_s("no. of tabs are %d\n", tbs);

	printf_s("no. of spaces are %d\n", bks);

	printf_s("no. of special charcaters are %d\n", sp);


	int x;
	scanf("%d", &x);



	return 0;
}