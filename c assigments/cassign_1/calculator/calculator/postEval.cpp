#include<iostream>
#include<string.h>
using namespace std;
bool isOperator(char);
int sub(int x, int y);


int mul(int x, int y);

int add(int x, int y);

int divi(int x, int y);
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
//evaluation of postfix exprssion
int postEval(char* str) {
	stack2 st(20);
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
						//res = a + b;
						res = add(a, b);
					else if (str[i] == '-')
						//res = b - a;
						res = sub(b, a);
					else if (str[i] == '*')
						res = mul(a, b);
					else if (str[i] == '/')
						res = divi(b, a);
					st.push(res);
					//cout << res;
				}

				else {
					cout << "not a correct expression" << endl;
					getchar();
					exit(-1);
				}

			}
			else {
				cout << "not a correct expression" << endl;
				getchar();
				exit(-1);
			}
		}
		else
		{
			if (str[i] != '@') {
				int x = 0;
				int ch;
				while (str[i] != '@') {
					ch = str[i] - 48;
					x = x * 10 + ch;
					//k = k * 10;
					//cout << x << " ";
					i++;
				}
				st.push(x);

			}
		}
	}
	return st.peek();
}