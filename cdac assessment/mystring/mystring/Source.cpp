//#include<iostream>
//#include<string.h>
//using namespace std;
//class MyString
//{
//	char *s;
//	int size;
//public:
//	// default constructor
//	MyString()
//	{
//		size = 0;
//		s = NULL;
//	}
//	// copy constructor	
//	MyString(const MyString &str)
//	{
//		size = strlen(str.s);
//		s = new char[size + 1];// dynamic memory allocation
//		strcpy_s(s, size,str.s);
//	}
//	// parameterized constructor
//	MyString(char a[], int len)
//	{
//		s = new char[len + 1];
//		
//		for (int i = 0; i < len; i++) {
//			s[i] = a[i];
//		}
//	}
//	// destructor
//	~MyString()
//	{
//		delete s;// freeing the memory
//	}
//	// + operator overloaded for concatination
//	void operator+(MyString str)
//	{
//		int x, i = 0, j;
//		x = strlen(str.s);
//		i = strlen(s);
//		for (j = i; j<i + x; j++)
//		{
//			s[j] = str.s[j - i];
//		}
//		s[j] = '\0';
//	}
//	// = operator overloaded for assignment 
//	MyString operator=(MyString str)
//	{
//		if (s != NULL) {
//			delete s;
//		}
//		size = str.size;
//		s = new char[size + 1];
//
//	/*	for (int i = 0; i < size; i++) {
//			s[i] = str.s[i];
//		}*/
//		strcpy(s,str.s);
//
//		return *this;
//	}
//	// >> operator overloaded for input
//	friend istream &operator >> (istream &cin, MyString &str)
//	{
//		cout << "enter size of string:";
//		std::cin >> str.size;
//		cout << "enter the string:";
//		str.s = new char[str.size + 1];
//		std::cin >> str.s;
//		return cin;
//	}
//	// << operator overloaded for output
//	
//	friend ostream &operator <<(ostream &cout, MyString str)
//	{
//		std::cout << "size is " << str.size << endl;
//		std::cout << "string is  " << str.s << endl;
//		return cout;
//	}
//	friend MyString * bubbleSort(MyString *arr, int len) {
//
//		for (int i = 0; i < len - 1; i++) {
//			int f = 0;
//			for (int j = 0; j < len - i - 1; j++) {
//				if (arr[j].s > arr[j + 1].s)
//				{
//					f = 1;
//					MyString temp;
//					temp = arr[j];
//					arr[j] = arr[j + 1];
//					arr[j + 1] = temp;
//					//swap(arr[j], arr[j + 1]);
//				}
//			}
//			if (f == 0)
//				break;
//		}
//		return arr;
//
//	}
//};
//
//
//int main() {
//	MyString obj("abc", 3), obj2,obj3;
//	cin >> obj2;
//	obj3 = obj2;
//	MyString *arr;
//	arr= new MyString[3];
//	cin >> arr[0];
//	cin >> arr[1];
//	cin >> arr[2];
//	arr=bubbleSort(arr, 3);
//
//
//
//}


/* Define string class with dynamic memory allocation for string. Define default
constructor, parameterized constructors, copy constructor, destructor, Overload +,
[], =, <<, >> operators. Observe the behavior of shallow copying and deep copying.*/
#include<iostream>
#include<string.h>
using namespace std;
class String
{
	char *s;
	int size;
public:
	// default constructor
	String()
	{
		size = 0;
		s = NULL;
	}
	// copy constructor	
	String(const String &str)
	{
		size = strlen(str.s);
		s = new char[size + 1];// dynamic memory allocation
		strcpy_s(s,size, str.s);
	}
	// parameterized constructor
	String(char a[], int len)
	{
		s = new char[len + 1];
		strcpy_s(s,len, a);
	}
	// destructor
	~String()
	{
		delete s;// freeing the memory
	}
	// + operator overloaded for concatination
	void operator+(String str)
	{
		int x, i = 0, j;
		x = strlen(str.s);
		i = strlen(s);
		for (j = i; j<i + x; j++)
		{
			s[j] = str.s[j - i];
		}
		s[j] = '\0';
	}
	// = operator overloaded for assignment 
	String operator=(String str)
	{
		if (s != NULL) {
			delete s;
		}
		size = str.size;
		s = new char[size + 1];
		strcpy_s(s,size, str.s);

		return *this;
	}
	// >> operator overloaded for input
	friend istream &operator >> (istream &cin, String &str)
	{
		cout << "enter size of string:";
		std::cin >> str.size;
		cout << "enter the string:";
		str.s = new char[str.size + 1];
		std::cin >> str.s;
		return cin;
	}
	// << operator overloaded for output
	friend ostream &operator <<(ostream &cout, String str)
	{
		std::cout << "size is " << str.size << endl;
		std::cout << "string is  " << str.s << endl;
		return cout;
	}
};
int main()
{
	String obj1, obj2("abc", 4);// obj3(obj2);
	// object initialization with various constructors

	cout << "enter a object 'obj1':" << endl;
	cin >> obj1;//<< operator overloaded for input
	cout << " string you have given obj1:\n";
	cout << obj1; // << operator overloaded for ouput
	cout << "string object which is initialized using parameters obj2\n";
	cout << obj2;
	cout << "concatination of string obj3 with obj2 \n";
	//obj2 + obj3;// concatination of strings using + operator
	cout << obj2;
	cout << " assignment of obj2 to obj1\n";
	obj1 = obj2;// assignmentof strings using = operator 
	cout << "obj1 is " << obj1;
	return 0;
}
