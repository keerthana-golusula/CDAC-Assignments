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
			s=new char[size+1];
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
			delete s;
		}
		// + operator overloaded for concatination
	void operator+(String s2)
		{
			int x,i=0,j;
			x=strlen(s2.s);
			i=strlen(s);
			for(j=i;j<i+x;j++)
			{
				s[j]=s2.s[j-i];
			}
		s[j]='\0';
		}
		// = operator overloaded for assignment 
	String operator=(String s1)
	{
			if(s!=NULL){
			delete s;	
		}
			size=s1.size;
			s=new char[size+1];
			strcpy(s,s1.s);
		
	return *this;
	}
	// >> operator overloaded for input
friend istream &operator >>(istream &cin, String &s1)
	{
		std::cin >> s1.size;
        s1.s=new char[s1.size+1];
		std::cin >> s1.s;
		return cin;
	}
	// << operator overloaded for output
	friend ostream &operator <<(ostream &cout, String s1)
		{
			std::cout << "size is " << s1.size << endl;
			std::cout << "string is  " << s1.s << endl;
			return cout;
		}
};
int main()
{
    String s1,s2("abc",4),s3(s2); // object initialization with various constructors
    cout<<"enter a object:"<<endl;
    cin>>s1;
    cout<< " string you have given:";
    cout<<"s1 is "<<s1;//<< operator overloaded for input
    cout<<"string object which is initialized using parameters";
    cout<<"s2 is "<<s2;  
    cout<<"concatination of string s3 with s2";
    s2+s3;// concatination of strings using + operator
    cout<<"s2 is "<<s2;// << operator overloaded for ouput 
    cout<<" assignment of s2 to s1";
	s1=s2;// assignmentof strings using = operator 
    cout<<"s1 is "<<s1;
	return 0;
}
