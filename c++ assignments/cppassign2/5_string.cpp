#include<iostream>
#include<string.h>
using namespace std;
class String
{
char *s;
int size;
public:
String()
{
size=0;
s=NULL;
}
String(const String &str)
{
size=strlen(str.s);
s=new char[size+1];
strcpy(s,str.s);
}
String(char a[],int len)
{
s=new char[len+1];
strcpy(s,a); 
}
~String()
{
delete s;
}
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
String operator=(String s1)
{
	if(s!=NULL){
		delete s;
	}else{
		size=s1.size;
		s=new char[size+1];
		strcpy(s,s1.s);
	}
return *this;
}
/*friend istream &operator >> (istream &cin, String &s1)
	{
		std::cin >> s1.size;
        s=new char[size+1];
		std::cin >> s1.s;
		return cin;
	}*/
friend ostream &operator <<(ostream &cout, String s1)
	{
		std::cout << "size is " << s1.size << endl;
		std::cout << "string is  " << s1.s << endl;
		return cout;
	}
};
int main()
{
String s1,s2("abc",4),s3(s2);
cout<<s2;
s2+s3;
s1=s2;
cout<<s2;
return 0;
}
