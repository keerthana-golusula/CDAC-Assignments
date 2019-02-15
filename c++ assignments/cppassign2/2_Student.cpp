#include<iostream>
#include<string>
using namespace std;
class Student{
	public:
	int rollno;
	string name;
	int marks1;
	int marks2;
	int marks3;
	int total;
	string grade;

  friend istream& operator>>(istream &,Student);	
  friend ostream& operator<<(ostream&,Student);
};

istream& operator>>(istream & in,Student &s){

int avg;
cin>>s.rollno>>s.name>>s.marks1>>s.marks2>>s.marks3;
s.total=s.marks1+s.marks2+s.marks3;
avg=s.total/3;
if(avg>60){
	s.grade="FirstClass";
}else if(avg>50)
s.grade="SecondClass";
else if(avg>40)
s.grade="ThirdClass";
else
s.grade="Fail";
 return cin;
}
ostream& operator<<(ostream& out,Student s){
	cout<<"student details are:"<<endl;
	cout<<s.rollno<<s.name<<s.marks1<<s.marks2<<s.marks3<<s.total<<s.total;
	return cout;
}
int main(){
	int n;
	istream in;
	ostream out;
	cin>>n;
	Student s[n];
	for(int i=0;i<n;i++){
		in>>s[i];
	}
	for(int i=0;i<n;i++){
		out<<s[i];
	}
}

