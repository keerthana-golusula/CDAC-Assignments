#include<stdio.h>
int main(){
	int x = 0x653210;
	char *p = &x;
	printf("%#x  %#x", x, *p);
	if (*p == 0x10) {
		printf("using processor is little endian\n");
	}
	else {
		printf("using processor is big endian\n");
	}

}