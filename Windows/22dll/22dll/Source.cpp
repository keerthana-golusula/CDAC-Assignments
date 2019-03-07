#include<stdio.h>
#include<windows.h>
#include "mydll.h"
typedef int(*MYPROC)(int, int);
int main() {
	int op;
	HMODULE hdll;
	MYPROC ADD,SUB,MUL,DIV;
	hdll = LoadLibraryEx(TEXT("mydll.dll"), NULL, NULL);
	if (hdll == NULL) {
		printf("dll file not loaded Error:%d", GetLastError());
		getchar();
		return -1;
	}
	while (1) {
		printf("choose the option\n1.add\n2.sub\n3.mul\n4.divi\n5.exit\n");
		scanf_s("%d", &op);
		switch (op) {
		case 1:
			ADD = (MYPROC)GetProcAddress(hdll, (LPCSTR)"add1");
			if (ADD == NULL) {
				printf("error: %d", GetLastError());
				getchar();
				return -1;
			}
			printf("sum of 10 and 20 is %d", ADD(10, 20));
			break;
		case 2:
			SUB = (MYPROC)GetProcAddress(hdll, (LPCSTR)"sub1");
			if (SUB == NULL) {
				printf("error: %d", GetLastError());
				getchar();
				return -1;
			}
			printf("difference of 20 and 10 is %d", SUB(20, 10));
			break;
		case 3:
			MUL = (MYPROC)GetProcAddress(hdll, (LPCSTR)"mul1");
			if (MUL == NULL) {
				printf("error: %d", GetLastError());
				getchar();
				return -1;
			}
			printf("product of 10 and 20 is %d", MUL(10, 20));
			break;
		case 4:
			DIV = (MYPROC)GetProcAddress(hdll, (LPCSTR)"div1");
			if (DIV == NULL) {
				printf("error: %d", GetLastError());
				getchar();
				return -1;
			}
			printf("division of 100 and 20 is %d", DIV(100, 20));
			break;
		case 5:
			exit(0);
		default:
			printf("enter valid option\n");
			break;
		}
	}
	FreeLibrary(hdll);
	system("pause");

}