#include<iostream>
using namespace std;

class Student {
     char studentname[30];
	 char grade[20];
	int marks1, marks2, marks3;
	
public:
	void setData(char * sn, char * f, int m1, int m2, int m3)
	{
		//studentname = new char *;
		strcpy(studentname, sn);
		//grade=new char
		strcpy(grade, f);
		marks1 = m1;
		marks2 = m2;
		marks3 = m3;
	 }
	float calculateAverage()
	{
		float avg;
		int tot = marks1 + marks2 + marks3;
		avg = tot / 3;
		return avg;
	}
	void computeGrade() {
		float avg = this->calculateAverage();
		if (avg > 60)
			strcpy(grade,"First Class");
		else if (avg > 50)
			strcpy(grade,"Second Class");
		else if (avg > 40)
			strcpy(grade,"Third Class");
		else
			strcpy(grade,"Fail");
	 }
	void display()
	{
		cout << "Name:" << this->studentname << endl;
		cout << "grade:" << this->grade;
		cout << "Marks1:" << this->marks1 << endl;
		cout << "Marks2:" << this->marks2 << endl;
		cout << "Marks3:" << this->marks3 << endl;
	}
	
};
int main() {
	Student s1;
//	CollegeCourse cc;
	s1.setData("keerthana", "second Class", 90, 85, 95);
	cout << "Average of marks is:" << s1.calculateAverage()<<endl;
    s1.computeGrade();
	s1.display();
}