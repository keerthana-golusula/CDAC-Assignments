/* Define string class with dynamic memory allocation for string. Define default
constructor, parameterized constructors, copy constructor, destructor, Overload +,
[], =, <<, >> operators. Observe the behavior of shallow copying and deep copying.*/
#include<iostream>
#include<string.h>
using namespace std;
class MyString
{
	char *name;
	int size;
public:
	// default constructor
	MyString()
	{
		size = 0;
		name = NULL;
	}
	// copy constructor	
	MyString(const MyString &str)
	{
		size = strlen(str.name);
		name = new char[size + 1];// dynamic memory allocation
		strcpy(name, str.name);
	}
	// parameterized constructor
	MyString(char a[], int len)
	{
		name = new char[len + 1];
		strcpy(name, a);
	}
	// destructor
	~MyString()
	{
		delete name;// freeing the memory
	}
	// + operator overloaded for concatination
	void operator+(MyString str)
	{
		int x, i = 0, j;
		x = strlen(str.name);
		i = strlen(name);
		for (j = i; j<i + x; j++)
		{
			name[j] = str.name[j - i];
		}
		name[j] = '\0';
	}
	// = operator overloaded for assignment 
	MyString operator=(MyString str)
	{
		if (name != NULL) {
			delete name;
		}
		size = str.size;
		name = new char[size + 1];
		strcpy(name, str.name);

		return *this;
	}
	bool operator<(MyString str) {
		if (strcmp(name, str.name)<0)
			return true;
		return false;
	}
	// >> operator overloaded for input
	friend istream &operator >> (istream &cin, MyString &str)
	{
		cout << "enter size of string:";
		std::cin >> str.size;
		cout << "enter the string:";
		str.name = new char[str.size + 1];
		std::cin >> str.name;
		return cin;
	}
	// << operator overloaded for output
	friend ostream &operator <<(ostream &cout, MyString str)
	{
		//std::cout << "size is " << str.size << endl;
		std::cout << "string is  " << str.name << endl;
		return cout;
	}
	// bubble sort function for sorting objects of Mystring class, it takes array of objects and its size as inputs and returns the sorted array.
		friend MyString* bubbleSort(MyString *arr, int len) {
			for (int i = 0; i < len-1 ; i++) {
				int f = 0;
				
				for (int j = 0; j < len - i-1; j++) {
					cout << arr[j].name <<" "<< arr[j + 1].name << endl;
					if (arr[j+1]< arr[j])
					{
						cout << "swap";
						//swap of two objects if next object is smaller than;
						f = 1;
						MyString temp;
						temp = arr[j];
						arr[j] = arr[j + 1];
						arr[j + 1] = temp;
						cout << arr[j].name << " " << arr[j + 1].name;
					}
					cout << "hello";
				}
				if (f == 0)
					break;
			}
			return arr;
	
		}
	
};

int main()
{
	MyString obj1, obj2("abc", 4), obj3(obj2);
	// object initialization with various constructors

	cout << "enter a object 'obj1':" << endl;
	cin >> obj1;//<< operator overloaded for input
	cout << " string you have given obj1:\n";
	cout << obj1; // << operator overloaded for ouput
	cout << "string object which is initialized using parameters obj2\n";
	cout << obj2;
	cout << "concatination of string obj3 with obj2 \n";
	obj2 + obj3;// concatination of strings using + operator
	cout << obj2;
	cout << " assignment of obj2 to obj3\n";
	obj3 = obj2;// assignmentof strings using = operator 
	cout << "obj3 is " << obj3;

	cout << "comparision of two objects:";
		if (obj1 < obj3)
			cout << "obj1 is less than obj3";
		else 
			cout << "obj1 is not less than obj3";
		int arrsize;
	MyString *arr;
	cout << "enter the size of array\n";
	cin >> arrsize;
	arr = new MyString[arrsize];
	for (int i = 0; i < arrsize; i++) {
		cin >>arr[i];
	}
	for (int i = 0; i < arrsize; i++)
		cout << arr[i] << " ";

	arr=bubbleSort(arr, arrsize);
	cout << "after sorting :";
	for (int i = 0; i < arrsize; i++)
		cout << arr[i] << " ";
 
		//delete arr;
	return 0;
}
