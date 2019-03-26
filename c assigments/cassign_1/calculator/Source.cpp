#include<iostream>
#include<string.h>
using namespace std;
  int precedence(char ch) {
	if (ch == '(')
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
class stack2 {
	int top;
	int *s;
	int size;
public:
	stack2() {
		top = -1;
		s = NULL;
		size = 0;

	}
	stack2(int x) {
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
	int peek() {
		return s[top];
	}
	void display() {
		if (isEmpty())
			cout << "stack is empty" << endl;
		for (int i = 0; i <= top; i++)
			cout << s[i] << " ";
	}
	~stack2() {
		delete s;
	}


};
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
			if(str[i]!='(')
           str2[k++]='@';
			if (st.isEmpty()) {
				st.push(str[i]);
				//st.display();
			}
			else {
				if (str[i] == '(')
					st.push(str[i]);
				else if (str[i] == ')') {
					while (st.peek() != '(')
						str2[k++] = st.pop();
					//cout << str2[k];
					st.pop();
				}
				else {
					while (st.peek() != -1 && precedence(str[i]) <= precedence(st.peek())) {
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
		if(str[i+1]=='\0'){
			str2[k++]='@';
		}

	}
	while (!st.isEmpty())
		str2[k++] = st.pop();
	str2[k++] = '\0';

  
	return str2;


}

long postEval(char* str) {
	stack2 st(20);
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		if (isOperator(str[i]))
		{
			if (!st.isEmpty()) {
				long a = st.pop();

				if (!st.isEmpty()) {
					long b = st.pop();

					long res;

					if (str[i] == '+')
						res = a + b;
					else if (str[i] == '-')
						res = b - a;
					else if (str[i] == '*')
						res = b*a;
					else if (str[i] == '/')
						res = b / a;
					st.push(res);
					cout<<res;
				}

				else {
					cout << "not a correct expression" << endl;
					exit(-1);
				}

			}
			else {
				cout << "not a correct expression" << endl;
				exit(-1);
			}
		}
		else
		{
			if (str[i] != '@') {
				long x = 0;
				long ch;
				while (str[i] != '@') {
					ch = str[i] - 48;
					x = x * 10 + ch;
					//k = k * 10;
					cout<<x<<" ";
					i++;
				}
				st.push(x);

			}
		}
	}
		return st.peek();
}


int main() {
	char str[20];
	char str2[20];
	cout << "enter the string" << endl;
	cin >> str; // input from string
	strcpy(str2,infixToPostfix(str));
   // cout << "postfix form of given string is: " << str2;
	long res;
	res=postEval(str2);
	cout << "result of the expression is:" << res;
}


