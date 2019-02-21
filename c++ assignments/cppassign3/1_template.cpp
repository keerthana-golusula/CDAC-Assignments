#include<bits/stdc++.h>
using namespace std;
template<class T>
int linear_search(T arr[],int size,T ele)
{
	for(int i=0;i<size;i++)
	{
		if(arr[i]==ele)
			return i;
	}
	return -1;
}
class Complex
{
	
	int real,imag;
	public:
		Complex()
		{
			real=imag=0;
		}
		Complex(int x,int y)
		{
			real=x;
			imag=y;
		}
		Complex(const Complex &b)
		{
			real=b.real;
			imag=b.imag;
		}
		~Complex()
		{}
		bool operator==(const Complex &a)
		{
			if(real==a.real&&imag==a.imag)
				return true;
			else
				return false;
		}
		friend istream& operator>>(istream& cin,Complex &b);//overloading cin
};
istream& operator>>(istream& cin,Complex &x)
{
	cin>>x.real>>x.imag;
	return cin;
}
int linear_search(const char *arr[],int size,char eles[20])//search function for char * type data
{
	for(int i=0;i<size;i++)
	{
		if(strcmp(arr[i],eles)==0)
			return i;
	}
	return -1;
}
int main()
{
	int res;
	int arrInt[]={1,2,3,4,5,6,7,8};
	res=linear_search(arrInt,10,6);
	if(res==-1)
	{
		cout<<"element not found\n";
	}
	else
	{
		cout<<"Element found at "<<res<<endl;
	}
	
	float arrFloat[]={1.0f,2.0f,3.0f,4.0f,5.0f,6.0f,7.0f};
	res=linear_search(arrFloat,10,10.0f);
	if(res==-1)
	{
		cout<<"element not found\n";
	}
	else
	{
		cout<<"Element found at "<<res<<endl;
	}

	double arrDouble[]={1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0};
 res=linear_search(arrDouble,10,5.0);
	if(res==-1)
	{
		cout<<"element not found\n";
	}
	else
	{
		cout<<"Element found at "<<res<<endl;
	}
	
	const char *arr[5]={"this","is","a","cpp", " assignment"};
	char eles[20]="cpp";
	res=linear_search(arr,4,eles);
	if(res==-1)
	{
		cout<<"element not found\n";
	}
	else
	{
		cout<<"Element found at "<<res<<endl;
	}
	
	Complex c(10,5),ar[5];
	cout<<"enter the complex objects \n";
	for(int i=0;i<5;i++)
	{
		cin>>ar[i];
	}
	res=linear_search(ar,5,c);
	if(res==-1)
	{
		cout<<"element not found\n";
	}
	else
	{
		cout<<"Element found at "<<res<<endl;
	}

	//system("pause");
	return 0;
}
