#include<iostream>
using namespace std;
class stack {
	int top;
	char *s;
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
		s = new char[x];
	}
	bool isFull() {
		return (top == size - 1);
	}
	bool isEmpty() {
		return top == -1;
	}
	void push(char x) {
		if (!isFull())
			s[++top] = x;
		else
			cout << "stack is Full" << endl;
	}
	char pop() {
		int x = -999;
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
	char peek() {
		if (!isEmpty())
			return s[top];
		else
			return -1;
	}
	~stack() {
		delete s;
	}


};
bool isBalancing(char *str) {

	stack st(20);
	for (int i = 0; i < strlen(str); i++) {
		char ch = str[i];
		switch (ch) {
		case '(':
			st.push(ch);
			break;
		case '[':
			st.push(ch);
			break;
		case '{':
			st.push(ch);
			break;
		case ')':
			if (st.isEmpty())
				return false;
			if (st.peek() == '(')
				st.pop();
			else
				return false;
			break;
		case ']':
			if (st.isEmpty())
				return false;
			if (st.peek() == '[')
				st.pop();
			else
				return false;
			break;

		case '}':
			if (st.isEmpty())
				return false;
			if (st.peek() == '{') {
				st.pop();
			}
			else
				return false;
			break;
		}
	}
	if(st.isEmpty())
		return true;
	else
		return false;
}
int main() {
	char str[20];
	cout << "enter the string to be balanced" << endl;
	cin >> str;
	if (isBalancing(str)) {
		cout << "given string is symbol balanced" << endl;
	}
	else {
		cout << "given string is not symbol balanced" << endl;
	}

}