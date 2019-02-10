#include<stdio.h>
int main(){
int i=0,j=0;
for(i=1;i<=5;i++){
for(j=1;j<=9;j++){
if(j<=(5-i)||j>=(5+i))
printf("  ");
else {
	if (j < 5) {
		printf("%d ", (6 - j));
	}
	else {
		printf("%d ", (j - 4));
	}
}

}
printf("\n");
}

}