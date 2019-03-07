#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
char* infixToPostfix(char *);
int postEval(char *);
//int precedence(char);
//bool isOperator(char);
int main() {
	char str[20];
	char str2[20];
	char str3[20];
	cout << "enter the string" << endl;
	cin >> str;
	//cout << str;
strcpy_s(str2, infixToPostfix(str));
	cout << "postfix form of given string is: " << str2;
	int res;
	res = postEval(str2);
	cout << "result of the expression is:" << res;

	system("pause");
}


