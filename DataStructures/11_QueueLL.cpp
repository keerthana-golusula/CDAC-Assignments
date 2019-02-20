#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node *next;
};
class queueLL
{
	Node *front, *rare;
public:
	queueLL()
	{
		front = NULL;
		rare = NULL;
	}
	void enque(int);
	void deque();
	void display();
};
void queueLL::enque(int e)
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
void queueLL::deque()
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
void queueLL::display()
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
	queueLL qu;
	do
	{
		cout << "enter any option:\n1.insert\t2.delete\t3.display\t4.exit\n";
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
		case 3:qu.display();
			break;
		case 4:
			exit(0);
		default:break;
		}
	} while (c != 4);
}
