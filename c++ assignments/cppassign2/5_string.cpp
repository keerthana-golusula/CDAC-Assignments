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
			size=0;
			s=NULL;
		}
	// copy constructor	
	String(const String &str)
		{
			size=strlen(str.s);
			s=new char[size+1];// dynamic memory allocation
			strcpy(s,str.s);
		}
		// parameterized constructor
	String(char a[],int len)
		{
		s=new char[len+1];
		strcpy(s,a); 
		}
		// destructor
	~String()
		{
			delete s;// freeing the memory
		}
		// + operator overloaded for concatination
	void operator+(String str)
		{
			int x,i=0,j;
			x=strlen(str.s);
			i=strlen(s);
			for(j=i;j<i+x;j++)
			{
				s[j]=str.s[j-i];
			}
		s[j]='\0';
		}
		// = operator overloaded for assignment 
	String operator=(String str)
	{
			if(s!=NULL){
			delete s;	
		}
			size=str.size;
			s=new char[size+1];
			strcpy(s,str.s);
		
	return *this;
	}
	// >> operator overloaded for input
	friend istream &operator >>(istream &cin, String &str)
		{
		cout << "enter size of string:";
			std::cin >> str.size;
			cout << "enter the string:";
			str.s=new char[str.size+1];
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
	String obj1,obj2("abc",4),obj3(obj2); 
	// object initialization with various constructors
   
	cout<<"enter a object 'obj1':"<<endl;
    cin>>obj1;//<< operator overloaded for input
    cout<< " string you have given obj1:\n";
    cout<<obj1; // << operator overloaded for ouput
    cout<<"string object which is initialized using parameters obj2\n";
    cout<<obj2;  
    cout<<"concatination of string obj3 with obj2 \n";
    obj2+obj3;// concatination of strings using + operator
    cout<<obj2; 
    cout<<" assignment of obj2 to obj1\n";
	obj1=obj2;// assignmentof strings using = operator 
    cout<<"obj1 is "<<obj1;
	return 0;
}
