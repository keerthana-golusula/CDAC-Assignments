#include<stdio.h>
#define Book(name,Author) #name"is written by"#Author
#define print(s) printf("token"#s"=%d",token##s)
int main() {
	int token9 = 100;
	print(9);
	printf("%s", Book(abc, xyz));
	return 0;
}