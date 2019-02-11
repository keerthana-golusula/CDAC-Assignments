#include<stdio.h>
struct time{
	int hours;
	int minutes;
	int seconds;
	
};
int main(){
	int f=0;
	struct time tm;
printf("enter time of a day\n");
scanf("%d",&tm.hours);	
scanf("%d",&tm.minutes);
scanf("%d",&tm.seconds);
if(tm.hours>23){
f=1;
printf("not valid time");
}
if(tm.minutes>59&&tm.minutes<0){
	f=1;
	printf("not a valid minutes");
}
if(tm.seconds>59 &&tm.seconds<0){
f=1;
printf("not valid seconds");
}
if(f==0){

	printf("the time is:\n ");
	printf("%d:%d:%d",tm.hours,tm.minutes,tm.seconds);
}
system("pause");
}
