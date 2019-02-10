#include<stdio.h>
int main() {
	char* color[7];
	//= { “red”,“green”,“blue”,“white”,“black”,“yellow” };
	color[0] = "red";
	color[1] = "green";
	color[2] = "blue";
	color[3] = "white";
	color[4] = "black";
	color[5] = "yellow";
	//a.What is the meaning of color ?
	printf("%d\n", color);
		//b.What is the meaning of(color + 2);
	printf("%d\n", color + 2);
		//c.What is the value of *color ?
	printf("%s\n", *color);
		//	d.What is the value of *(color + 2) ?
		printf("%s\n", *(color + 2));
	//e.How do color[5] and *(color + 5) differ ? .
	printf("%s %s\n", color[5], *(color + 5));
}