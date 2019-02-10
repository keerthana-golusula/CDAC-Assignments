#include<stdio.h>
int main() {
	float table[2][3] = { { 1.1,1.2,1.3 },{ 2.1,2.2,2.3 } };

	printf("%d\n", table);
	//a) What is the meaning of a table ?
	//b) What is the meaning of(table + 1) ?
	printf("%d\n", table + 1);
		//c) What is the meaning of *(table + 1) ?
		printf("%d\n", *(table + 1));
		//d) What is the meaning of(*(table + 1) + 1) ?
	printf("%d\n", (*(table + 1) + 1));
		
	//e) What is the meaning of(*(table)+1) ?
	printf("%d\n", *(table)+1);
		//f) What is the value of *(*(table + 1) + 1) ?
	printf("%f\n", *(*(table + 1) + 1));
		//g) What is the value of *(*(table)+1) ?
	printf("%f\n", *(*(table)+1));
	//	h) What is the value of *(*(table + 1) ?
	printf("%f\n", *(*(table + 1)));
		//	i) What is the value of *(*(table)+1) + 1 ?
	printf("%f\n", *(*(table)+1) + 1);
	scanf("%f", &table[0][0]);

}