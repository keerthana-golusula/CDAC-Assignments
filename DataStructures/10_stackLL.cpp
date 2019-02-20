
#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node *next;
};
class StackLL
{
	Node *top;
public:
	StackLL()
	{
		top = NULL;
	}
	void push(int);
	int pop();
	void display();
};
void StackLL::push(int e)
{
	Node *t;
	t = new Node;
	t->data = e;
	t->next = top;
	top = t;
}
int StackLL::pop()
{
	if (top == NULL)
	{
		cout << "stack is empty";
		return 0;
	}
	else
	{
		Node *temp;
		temp = top;
		int e = top->data;
		top = top->next;
		delete temp;
		return e;
	}
}
void StackLL::display()
{
	Node *temp;
	temp = top;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}
int main()
{
	int c, e;
	StackLL st;
	do
	{
		cout << "enter any option:\n1.push\t2.pop\t3.display\t4.exit\n";
		cin >> c;
		switch (c)
		{
		case 1:cout << "enter the element to be inserted:";
			cin >> e;
			st.push(e);
			break;
		case 2:e = st.pop();
			cout << "the element deleted is:" << e << endl;
			break;
		case 3:st.display();
		case 4:
			exit(0);
			break;
		default:break;
		}
	} while (c != 4);
}
