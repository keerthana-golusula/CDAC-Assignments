#include<iostream>
using namespace std;
#define SIZE 10
template<class T>
class Stack
{
    int size;
	int top;
	T *arr;
	public:
		stack(){
			size=0;
			top=-1;
			arr=NULL;
		}
		Stack(int x)
		{
			size=x;
			top=-1;
			arr=new T[x];
		}
		~Stack()
			{
			}
		void push (T x)
		{
			try
			{
				if(top==size-1)
				{
					cout<<"stack is full\n";
					throw "can't push into the stack";
				}
				arr[++top]=x;
			}
			catch(char *s)
			{
				cout<<s<<endl;
			}
		}
		T pop()
		{
			try
			{
				if(top==-1)
				{
					cout<<"stack is empty\n";
					throw "can't pop from the stack";
				}
				return arr[top--];
			}
			catch(char *s)
			{
				cout<<s<<endl;
			}
		}
    void display(){
    	for(int i=0;i<size;i++){
    		cout<<arr[i]<<" ";
		}
	}
	
};
int main()
{
int n,op,x;

	cout<<"stack for int elements"<<endl;
	
	cout<<"enter size for stack";
	cin>>n;
		Stack<int> s1(n);
	 while(1){

	cout<<"choose your choice:"<<endl;
	cout<<"1.push"<<endl;
	cout<<"2.pop"<<endl;
	cout<<"3.display"<<endl;
	cin>>op;
	if(op>=4){
		break;
	}
	switch(op){
		case 1:
			cout<<"enter the element to be pushed";
			cin>>x;
			s1.push(x);
			break;
		case 2:
				x=s1.pop();
				cout<<"popped element is:"<<x;
				break;
	      case 3:
		  	s1.display();
		  	break;
	}
}
	
	cout<<"stack for float elements  "<<endl;
	 cout<<"enter size for stack";
	cin>>n;
		Stack<float> s2(n);
		float x2;
	 while(1){

	cout<<"choose your choice:"<<endl;
	cout<<"1.push"<<endl;
	cout<<"2.pop"<<endl;
	cout<<"3.display"<<endl;
	cin>>op;
	if(op>=4){
		break;
	}
	switch(op){
		case 1:
			cout<<"enter the element to be pushed";
			cin>>x2;
			s2.push(x);
			break;
		case 2:
				x=s2.pop();
				cout<<"popped element is:"<<x;
				break;
	      case 3:
		  	s2.display();
		  	break;
	}
}
	
	return 0;
}
