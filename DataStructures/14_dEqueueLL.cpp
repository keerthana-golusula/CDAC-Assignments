#include<iostream>
using namespace std;
struct Node {
	int data;
	struct Node* next;
};
class dEqueueLL
{
	Node *front, *rare;
public:
	dEqueueLL()
	{
		front = NULL;
		rare = NULL;
	}
	void enque(int);
	void deque();
	void enquef(int);
	void dequer();
	void display();
};
void dEqueueLL::enque(int e)
{
	Node *temp;
	temp = new Node;
	temp->next = NULL;
	temp->data = e;
	if (rare == NULL)
	{
		rare = temp;
		front = temp;
	}
	else
	{
		rare->next = temp;
		rare = temp;
	}
}
void dEqueueLL::deque()
{
	int e;
	Node *temp = front;
	if (front == NULL)
		cout << "queue is empty.deletion is not possible\n";
	else if (rare == front)
	{
		e = front->data;
		rare = NULL;
		front = NULL;
		cout << "element deleted is:" << e << endl;
	}
	else
	{
		e = front->data;
		front = front->next;
		cout << "element deleted is:" << e << endl;
	}
	delete temp;
}
void dEqueueLL::enquef(int e) {
	Node *temp;
	temp = new Node;
	temp->next = NULL;
	temp->data = e;
	if (rare == NULL)
	{
		rare = temp;
		front = temp;
	}
	else {
		temp->next = front;
		front = temp;
	}

}
void dEqueueLL::dequer() {
	int e;
	struct Node *temp;
	if (front == NULL)
		cout << "queue is empty.deletion is not possible\n";
	else if (rare == front)
	{
		temp= front;
		e = front->data;
		rare = NULL;
		front = NULL;
		cout << "element deleted is:" << e << endl;
		
	}
	else
	{
		temp = front;
		while (temp->next != rare) {
			temp = temp->next;
		}
		e = temp->next->data;
		//e = temp->data;
		rare = temp;
		temp = temp->next;
		cout << "element deleted is:" << e << endl;
		
	}
	delete temp;
	

}

void dEqueueLL::display()
{
	Node *temp;
	temp = front;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
int main()
{
	int c, e;
	dEqueueLL qu;
	do
	{
		cout << "enter any option:\n1.insert\t2.delete\t3.insert from front\t4.delete from back\t5.display\t6.exit\n";
		cin >> c;
		switch (c)
		{
		case 1:cout << "enter the element to be inserted:";
			cin >> e;
			qu.enque(e);
			break;
		case 2:qu.deque();
			//cout << "deleted elmenent is:" << e << endl;
			break;
		case 3:cout << "enter the element to be inserted:";
			cin >> e;
			qu.enquef(e);
			break;
		case 4:
			qu.dequer();
			break;
		case 5:qu.display();
			break;
		case 6:
			exit(0);
		default:
			cout << "choose valid Option!!" << endl;
			break;
		}
	} while (1);
}
