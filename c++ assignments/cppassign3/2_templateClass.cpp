#include<iostream>
#include<string>
using namespace std;

template<class T>
// template class definition
class Stack
{
    int size;
	int top;
	T *arr;
	public:
		// default constructor
		Stack(){
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
	void pop()
		{
			try
			{
				if(top==-1)
				{
					cout<<"stack is empty\n";
					throw "can't pop from the stack";
					
				}
				else {
					T ret = arr[top--];
				//	delete arr[top--];
					cout << "popped element is:" << ret;
					//return ret;
				}
			}
			catch(char *s)
			{
				cout<<s<<endl;
			}
		}
		// display function definition
    void display(){
    	for(int i=0;i<=top;i++){
    		cout<<arr[i]<<" ";
		}
	}
	
};
class complex {
	float real;
	float img;
public:
	complex() {
		real = img = 0;
	}
	complex(float a, float b) {
		real = a;
		img = b;
	}
	complex(complex &c) {
		real = c.real;
		img = c.img;
	}
	~complex() {
		//cout << "in destructor";
	}

	complex operator=(complex c) {
		real = c.real;
		img = c.img;
		return *this;
	}
	friend ostream& operator<<(ostream&, complex c);
	friend istream& operator >> (istream&, complex &c);
};

ostream& operator<<(ostream& cout, complex c) {
	std::cout << c.real << "+i" << c.img << endl;
	return cout;
}
istream& operator >> (istream& cin, complex &c) {
	cin >> c.real >> c.img;
	return cin;
}
int main()
{
	int size,option,stackOption;
	cout << "choose the type of stack:";
	cout << "1.int\n2.float\n3.complex\n4.String\n";
		cin >> stackOption;
	switch (stackOption) {
	case 1:
	{
		cout << "stack for int elements" << endl;
		cout << "enter size for stack";
		cin >> size;
		Stack<int> IntStack(size);
		int ele;
		while (1) {
			cout << "choose your choice:" << endl;
			cout << "1.push" << endl;
			cout << "2.pop" << endl;
			cout << "3.display" << endl;
			cout << "4.exit" << endl;
			cin >> option;
			switch (option) {
			case 1:
				cout << "enter the element to be pushed";
				cin >> ele;
				IntStack.push(ele);
				break;
			case 2:
				 IntStack.pop();
				break;
			case 3:
				IntStack.display();
				break;
			case 4:
				exit(0);
			default:
				cout << "choose valid option";
				break;
			}
		}
		break;
	}
	case 2:
	{ // flaot stack object definition
		cout << "stack for float elements  " << endl;
		cout << "enter size for stack";
		cin >> size;
		Stack<float> FloatStack(size);
		float ele2;
		while (1) {

			cout << "choose your choice:" << endl;
			cout << "1.push" << endl;
			cout << "2.pop" << endl;
			cout << "3.display" << endl;
			cout << "4.exit" << endl;
			cin >> option;
			switch (option) {
			case 1:
				cout << "enter the element to be pushed";
				cin >> ele2;
				FloatStack.push(ele2);
				break;
			case 2:
				FloatStack.pop();
				
				break;
			case 3:
				FloatStack.display();
				break;
			case 4:
				exit(0);
			default:
				cout << "choose valid option";
				break;
			}
		}
		break;
	}
	case 3:
	{	// complex stack object definition
		cout << "stack for complex elements  " << endl;
		cout << "enter size for stack";
		cin >> size;
		Stack<complex> ComplexStack(size);
		complex ele3;
		while (1) {

			cout << "choose your choice:" << endl;
			cout << "1.push" << endl;
			cout << "2.pop" << endl;
			cout << "3.display" << endl;
			cout << "4.exit" << endl;
			cin >> option;
			
			switch (option) {
			case 1:
				cout << "enter the element to be pushed";
				cin >> ele3;
				ComplexStack.push(ele3);
				break;
			case 2:
				 ComplexStack.pop();
			
				break;
			case 3:
				ComplexStack.display();
				break;
			case 4:
				exit(0);
			default:
				cout << "choose valid option";
				break;
			}
		}
		break;
	}
	case 4:
	{	// string stack object definition
		cout << "stack for string elements  " << endl;
		cout << "enter size for stack";
		cin >> size;
		Stack<string> StringStack(size);
		string ele4;
		while (1) {

			cout << "choose your choice:" << endl;
			cout << "1.push" << endl;
			cout << "2.pop" << endl;
			cout << "3.display" << endl;
			cout << "4.exit" << endl;
			cin >> option;

			switch (option) {
			case 1:
				cout << "enter the element to be pushed";
				cin >> ele4;
				StringStack.push(ele4);
				break;
			case 2:
				 StringStack.pop();

				break;
			case 3:
				StringStack.display();
				break;
			case 4:
				exit(0);
			default:
				cout << "choose valid option";
				break;
			}
		}
		break;
	}
	default:
		cout << "enter valid option";
		break;
	}
	
	return 0;
}
