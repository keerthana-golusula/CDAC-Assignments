#include<stdio.h>
struct st1{
	int var1;
	char var2;
};
union uni{
	int var3;
	char var4;
};
int main(){
	struct st1 s;
	union uni u;
	printf("size of struct: %d",sizeof(s));
	printf("size of union : %d",sizeof(u));
	
	
}
