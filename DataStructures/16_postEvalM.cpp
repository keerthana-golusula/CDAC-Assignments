#include<iostream>
//#include<stack>
using namespace std;
bool isOperator(char ch) {
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
		return true;
	return false;
}
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
	int peek() {
		return s[top];
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
int postEval(char* str) {
	stack st(20);
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		if (isOperator(str[i]))
		{
			if (!st.isEmpty()) {
				int a = st.pop();

				if (!st.isEmpty()) {
					int b = st.pop();

					int res;

					if (str[i] == '+')
						res = a + b;
					else if (str[i] == '-')
						res = b - a;
					else if (str[i] == '*')
						res = b*a;
					else if (str[i] == '/')
						res = b / a;
					st.push(res);
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
				int x = 0, ch;
				while (str[i] != '@') {
					ch = str[i] - 48;
					x = x * 10 + ch;
					//k = k * 10;
					i++;
				}
				st.push(x);

			}
		}
	}
		return st.peek();
}
int main() {
	char str[30];
	cout << "enter postfix expresion using @ as delimiter";
	cin >> str;
	int res;
	res=postEval(str);
	cout << "result of the expression is:" << res;
}