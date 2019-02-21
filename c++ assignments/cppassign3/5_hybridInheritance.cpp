#include<bits/stdc++.h>
using namespace std;
class person 
{
	public:
		string name;
		int age;
		person()
		{
			name="raj";
			age=20;
		}
		void displayn()
		{
			cout<<"name: "<<name<<" "<<"age:"<<age<<endl;
		}
};

class physique : virtual public person
{
	public:
		int height;
		int weight;
		physique()
		{
			height=10;
			weight=50;
		}
		void displayp()
		{
			
			cout<<"the person height and weight are "<<height<<" "<<weight<<endl;
		}
};
class family: virtual public person
{
	public:
		int numChildren;
		string religion;
		family()
		{
			numChildren=2;
			religion="hindu";
		}
		void displayf()
		{
			
			cout<<"the number of children are "<<numChildren<<" and religion is "<<religion<<endl;
		}
};
class employee: public physique, public family
{
	public:
		int emno;
		int salary;
		employee()
		{
			emno=14;
			salary=50000;
		}
		void displaye()
		{
			displayn();
			displayp();
			displayf();
			cout<<"the employee number is "<<emno<<" salary is "<<salary<<endl;
		}
};
int main()
{
	employee o1;
	
	o1.displaye();
	
	return 0;
}
