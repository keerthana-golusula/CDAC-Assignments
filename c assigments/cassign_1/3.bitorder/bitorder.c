#include<stdio.h>
int rev = -1, rot = -1,res=-1;

int main() {
	int num = 0xCAFE;
	res = threeon(num);
	//printf("%d", res);
	if (res>=3){
		printf("given number has atleast three least significant bits are on");
}
	else {
		printf(" given number has no three bits on in its four lsbs");
	}
	rev = byteorderrev(num);
	printf("%#x", rev);
	rot = rotatebyone(num);
	printf("%#x", rot);
	
	int x;
	scanf_s("%d", &x);


}
