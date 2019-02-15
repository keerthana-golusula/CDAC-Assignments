#include<iostream>
using namespace std;
class Polar{
	int angle;
	int radius;

	public:
		static int count;
		Polar(){
			count++;
			angle=0;
			radius=0;
		}
		Polar(int x,int y){
			angle=x;
			radius=y;
			count++;
		}
		Polar(Polar &p){
			count++;
			radius=p.radius;
			angle=p.angle;
		}
};
int Polar::count=0;
int main(){
	Polar p1,p2(30,4);
	cout<<"no. of active objects are:"<<p2.count<<endl;
	Polar p3,p4(p2);
	cout<<"Present no. of active objects are:"<<p2.count<<endl;
	
}
