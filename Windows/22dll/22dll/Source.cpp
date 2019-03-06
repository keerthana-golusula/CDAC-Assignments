#include<stdio.h>
#include<windows.h>
#include "mydll.h"
typedef int(*MYPROC)(int, int);
int main() {
	HMODULE hdll;
	MYPROC ADD,SUB,MUL,DIV;
	hdll = LoadLibraryEx(TEXT("mydll.dll"), NULL, NULL);
	if (hdll == NULL) {
		printf("dll file not loaded Error:%d", GetLastError());
		getchar();
		return -1;
	}
	ADD = (MYPROC)GetProcAddress(hdll, (LPCSTR)"add1");
	if (ADD == NULL) {
		printf("error: %d", GetLastError());
		getchar();
		return -1;
	}
	printf("sum of 10 and 20 is %d",ADD(10, 20));
	FreeLibrary(hdll);
	system("pause");

}