#include<iostream>
using namespace std;
class stack {
	int top;
	int *s;
	int size;
public:
	stack() {
		top = -1;
		s = NULL;
		size = 0;

	}
	stack(int x) {
		top = -1;
		size = x;
		s = new int[x];
	}
	bool isFull() {
		return (top == size - 1);
	}
	bool isEmpty() {
		return top == -1;
	}
	void push(int x) {
		if (!isFull())
			s[++top] = x;
		else
			cout << "stack is Full" << endl;
	}
	int pop() {
		//int x = -999;
		if (!isEmpty())
		return s[top--];
		else {
			cout << "Stack is Empty" << endl;
			return -1;
		}
			//return x;
	}
	void display() {
		if (isEmpty())
			cout << "stack is empty" << endl;
		for (int i = 0; i <= top; i++)
			cout << s[i] << " ";
	}
	~stack() {
		delete s;
	}


};
int main() {
	cout << " enter the size of stack" << endl;
	int s, op, x;
	cin >> s;
	stack st(s);
	while (1) {
		cout << "enter the option" << endl;
		cout << "1.push the element" << endl;
		cout << "2.Pop the element" << endl;
		cout << "3.display the element" << endl;
		cout << "4.Exit" << endl;
		cin >> op;
		switch (op) {
		case 1:
			cout << "enter element to be pushed\n";
			cin >> x;
			st.push(x);
			break;
		case 2:
			x = st.pop();
			if(x!=-1)
			cout << "the deleted element is :" << x;
			break;
		case 3:
			st.display();
			break;
		case 4:
			exit(0);
		default:
			cout << "choose valid option" << endl;
		}
	}
}