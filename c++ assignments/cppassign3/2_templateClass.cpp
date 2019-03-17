#include<iostream>
using namespace std;
#define SIZE 10
template<class T>
// template class definition
class Stack
{
    int size;
	int top;
	T *arr;
	public:
		// default constructor
		stack(){
			size=0;
			top=-1;
			arr=NULL;
		}
		// parameterized constructor
		Stack(int x)
		{
			size=x;
			top=-1;
			arr=new T[x];
		}
		// destructor
		~Stack()
			{
				delete arr; 
			}
			// push function definiton
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
		// pop function definiton
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
		// display function definition
    void display(){
    	for(int i=0;i<size;i++){
    		cout<<arr[i]<<" ";
		}
	}
	
};
int main()
{
int size,option,ele;

	cout<<"stack for int elements"<<endl;
	cout<<"enter size for stack";
	cin>>size;
		Stack<int> IntStack(size);
	 while(1){
	cout<<"choose your choice:"<<endl;
	cout<<"1.push"<<endl;
	cout<<"2.pop"<<endl;
	cout<<"3.display"<<endl;
	cin>>option;
	if(option>=4){
		break;
	}
	switch(option){
		case 1:
			cout<<"enter the element to be pushed";
			cin>>ele;
			IntStack.push(ele);
			break;
		case 2:
				ele=IntStack.pop();
				cout<<"popped element is:"<<ele;
				break;
	      case 3:
		  	IntStack.display();
		  	break;
	}
}
	// flaot stack object definition
	cout<<"stack for float elements  "<<endl;
	 cout<<"enter size for stack";
	cin>>size;
		Stack<float> FloatStack(size);
		float ele2;
	 while(1){

	cout<<"choose your choice:"<<endl;
	cout<<"1.push"<<endl;
	cout<<"2.pop"<<endl;
	cout<<"3.display"<<endl;
	cin>>option;
	if(option>=4){
		break;
	}
	switch(option){
		case 1:
			cout<<"enter the element to be pushed";
			cin>>ele2;
			FloatStack.push(ele2);
			break;
		case 2:
				ele2=FloatStack.pop();
				cout<<"popped element is:"<<ele2;
				break;
	      case 3:
		  	FloatStack.display();
		  	break;
	}
}
	
	return 0;
}
