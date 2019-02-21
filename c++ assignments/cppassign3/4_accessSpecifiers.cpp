#include<iostream>
using namespace std;
class Base{
	private:
	int x=10;
	protected:
	int y=20;
	public:
	int z=30;
   virtual void display(){
		cout<<" x:"<<x<<" y:"<<y<<" z:"<<z<<endl;
}
	
};
class Derived1:private Base{
	public:
	void display(){
		cout<<"nothing will be printed as it is private";
		//	cout<<" x:"<<x<<" y:"<<y<<" z:"<<z<<endl;
}
};
class Derived2:protected Base{
	public:
	void display(){
		//cout<<" x:"<<x<<endl;    private member cannot be accessed in protected class
		cout<<" y:"<<y<<" z:"<<z<<endl;
}
	
};
class Derived3:public Base{
	public:
	void display(){
			//cout<<" x:"<<x<<endl;
			// private member cannot be accessed in public class
			cout<<" y:"<<y<<" z:"<<z<<endl;
   
	}
};
int main(){
	Base b;
	b.display();
	
	Derived1 d1;
	d1.display();
	Derived2 d2;
	d2.display();
	Derived3 d3;
	d3.display();
	
}
