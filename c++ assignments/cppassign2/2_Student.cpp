#include<iostream>
#include<string>
using namespace std;
char grades[4][20] = { "FirstClass","secondClass","thirdclass","Fail" };
class Student{
	
	int rollno;
	char name[30];
	int marks1;
	int marks2;
	int marks3;
	int total;
	char grade[20];
public:
	friend void generateResults(Student *, int n);
  friend istream& operator>>(istream &,Student&);	
  friend ostream& operator<<(ostream&,Student);
};

istream& operator>>(istream & cin,Student &s){

int avg;
cout << "Enter roll no." << endl;
cin >> s.rollno;
cout << "enter name:" << endl;
cin >> s.name;
cout << "enter marks1:" << endl;
cin >> s.marks1;
cout << "enter marks2:" << endl;
cin >> s.marks2;
cout << "enter marks:" << endl;
cin>> s.marks3;
s.total=s.marks1+s.marks2+s.marks3;
avg=s.total/3;
if(avg>60){
	strcpy(s.grade,grades[0]);
}else if(avg>50)
strcpy(s.grade,grades[1]);
else if(avg>40)
strcpy(s.grade,grades[2]);
else
strcpy(s.grade,grades[4]);
 return cin;
}
void generateResults(Student *s, int n) {
	/*cout << "Roll_No name marks1 Marks2 marks3 Total Grade" << endl;
	for (int i = 0; i < n; i++) {
		cout << s[i].rollno << " " << s[i].name << " " << s[i].marks1 << " " << s[i].marks2 << " " << s[i].marks3 << " " << s[i].total << " " << s[i].grade << endl;
	}*/
	for (int i = 0; i < n; i++) {
		cout << "student "<<i+1<<" details are:" << endl;
		cout << s[i];
	}
}

ostream& operator<<(ostream& cout,Student s){
	
	cout<<"RollNo:"<<s.rollno<<"\nName:"<<s.name<<"\nMarks1:"<<s.marks1<<"\nMarks2:"<<s.marks2<<"\nmarks3:"<<s.marks3<<"\ntotal:\n"<<s.total<<"\nGrade:\n"<<s.grade;
	return cout;
}
int main(){
	int n;
	cout << "enter no. of students:";
	cin>>n;
	Student *s;
		s=new Student[n];
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	generateResults(s, n);
	/*for(int i=0;i<n;i++){
		cout<<s[i];
	}*/
}

