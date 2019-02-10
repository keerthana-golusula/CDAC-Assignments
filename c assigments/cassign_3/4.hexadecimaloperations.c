#include<stdio.h>
void mask(int);
void shift(int);
int main() {
	int hex,one,c;
	printf("enter a hexadecimal input on which operations are to be performed");
	scanf("%x", &hex);
	printf("%x", hex);
	while (1) {
		printf("choose your choice of operation:\n1.ones compliment\n2.masking operation\n3.shift operation\n4.exit");
		scanf("%d", &c);
		switch (c) {
		case 1:

			one = ~hex;
			printf("ones compliment of %x is %x", hex, one);
			break;
		case 2:
			mask(hex);
			break;
		case 3:
			shift(hex);
			break;
		case 4:
			exit(1);
			break;

		}
	}
	int x;
	scanf("%d", &x);
}
void mask(hex) {
	int mask, res,c;
	printf("choose which mask operation to do:\n1.bitwise and\n2.bitwise or\n3.bitwise exclusive or");
		scanf("%d", &c);
	printf("enter hexadecimal value to with masking should be done");
	scanf("%x", &mask);
	switch (c) {
	case 1:
		res = hex&mask;
		break;
	case 2:
		res = hex | mask;
		break;
	case 3:
		res = hex^mask;
		break;
	}
	printf("after masking operation result is %x", res);
}
void shift(hex) {
	int c, res, n;
	printf("choose which side to be shifted:\n1.right shift\n2.left shift");
	scanf("%d", &c);
		printf("enter no of bits to be shifted");
	scanf("%d", &n);
	switch (c) {
	case 1:
		res = hex >> n;
		break;

	case 2:
		res = hex << n;
		break;
	}
	printf("shifting operation result is %x", res);

}