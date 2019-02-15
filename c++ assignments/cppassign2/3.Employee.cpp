#include<iostream>
#include<string.h>
using namespace std;
class Employee{
	int empno;
	char name[30];
	int salary;
	public:
		/*Employee(int no,char* name,int sal){
			empno=no;
			strcpy(name,name);
			salary=sal;
		}*/
		~Employee(){
			cout<<"employee destroyed";
		}
	void setData(int no,char * str,int sal){
			empno=no;
			strcpy(name,str);
			salary=sal;
		}
		friend istream& operator>>(istream& cin ,Employee &e);
		friend ostream& operator<<(ostream& cout,Employee e);	
	
};
istream& operator>>(istream& cin,Employee &e){
	cin>>e.empno>>e.name>>e.salary;
	return cin;
}
ostream& operator<<(ostream& cout,Employee e){
	cout<<e.empno<<" "<<e.name<<" "<<e.salary<<endl;
	return cout;
}
int main(){
	int n;
	cout<<"enter no. of employees\n";
	cin>>n;
	Employee *emp;
	emp= new Employee[n];
	for(int i=0;i<n;i++){
		cout<<"enter employee"<<i+1<<":";
		cin>>emp[i];
	}
	for(int i=0;i<n;i++){
		cout<<emp[i]<<endl;
	}
}


