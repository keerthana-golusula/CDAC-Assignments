#include<iostream>
#include<string>
using namespace std;
int precedence(char ch) {
	if (ch == ')')
		return 0;
	if (ch == '+' || ch == '-')
		return 1;
	if (ch == '*' || ch == '/')
		return 2;
}
bool isOperator(char ch) {
	if (ch == '(' || ch == ')' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
		return true;
	return false;
}
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
		//int x = -999;
		if (!isEmpty())
			return s[top--];
		else {
			cout << "Stack is Empty" << endl;
			return '~';
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
char* infixToPostfix(char * str) {
	stack st(20);
	char str2[20];
	int k = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (isOperator(str[i])) {
			if (st.isEmpty()) {
				st.push(str[i]);
				//st.display();
			}
			else {
				if (str[i] == ')')
					st.push(str[i]);
				else if (str[i] == '(') {
					while (st.peek() != ')')
						str2[k++] = st.pop();
					cout << str2[k];
					st.pop();
				}
				else {
					while (st.peek() != -1 && precedence(str[i]) < precedence(st.peek())) {
						str2[k++] = st.pop();
						//cout<<str2[k];
						//st.display();
					}
					st.push(str[i]);
				}
			}
		}
		else {
			str2[k++] = str[i];
		}

	}
	while (!st.isEmpty())
		str2[k++] = st.pop();
	str2[k++] = '\0';

	return str2;


}

int main() {
	char str[20];
	char str2[20];
	cout << "enter the string" << endl;
	cin >> str;
	strrev(str);
	strcpy(str2, infixToPostfix(str));
	strrev(str2);
	cout << "postfix form of given string is: " << str2;
}