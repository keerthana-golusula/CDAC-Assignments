#include<iostream> 
using namespace std; 
  
class shape 
{ 
public: 
    virtual void display_area () 
    { 
    	cout<< "print area of Any shape class" <<endl; 
    } 
}; 
  
class Triangle:public shape 
{ 
int b,h;
public:
Triangle(int a,int c){
	b=a;
	h=c;
} 
    void display_area () 
    { 
    	cout<< "Area of Triangle class:" <<endl; 
         int area=0.5*b*h;
         cout<<area;
    } 
}; 
  
class Rectangle:public shape 
{ 
int a,b;
public:
Rectangle(int c,int d){
	a=c;
	b=d;
} 
    void display_area () 
    { 
    	cout<< "Area of Rectangle class" <<endl; 
        int area=a*b;
        cout<<area;
	} 
};

class Square:public shape 
{ 
int a;
public: 
Square(int s){
	a=s;
}
    void display_area () 
    { 
    	cout<< "Area of Square class" <<endl; 
         int area=a*a;
         cout<<area;
    } 
};

int main() 
{ 
	
    shape *bptr; 
    Triangle T(10,20); 
    bptr = &T;   
    bptr->display_area();
    Square S(5);
    bptr = &S;    
    bptr->display_area();
    Rectangle R(10,5);
    bptr = &R;    
    bptr->display_area();
   
} 
