#include<stdio.h>
struct date {
	int y, m, d;
};
const int mon[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
int countLeap(struct date d) {
	int year = d.y;
	if (d.m < 1||(d.m=1&&d.d<29)) {
		year--;
	}
	return ((year / 4) - (year / 100) + (year / 400));
}

long diffInDates(struct date d1, struct date d2) {
	long int days1, days2;
	days1 = d1.y * 365+ d1.d;
	d1.m=d1.m-2;
	while (d1.m<=0) {
		days1 += mon[d1.m];
			d1.m--;
	}
	days1 += countLeap(d1);
	
	days2 = d2.y * 365+d2.d;
	d2.m = d2.m - 2;
	while (d2.m <= 0) {
		days2 += mon[d2.m];
			d2.m--;
	}
	days2 += countLeap(d2);

	return abs(days1 - days2);
}
int main(){
	struct date d1, d2;
	long int diff;
	printf("Enter first date in dd mm yyyy:");
	scanf("%d%d%d", &d1.d, &d1.m, &d1.y);
	printf("enter second date in dd mm yyyy:");
	scanf("%d%d%d", &d2.d, &d2.m, &d2.y);
	diff = diffInDates(d1, d2);
	printf("%ld", diff);
}