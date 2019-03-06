#include "mydll.h"
#include<stdio.h>
#include<windows.h>
BOOL WINAPI DllMain(HANDLE hand, DWORD msg, LPVOID res) {
	switch (msg) {

	case DLL_PROCESS_ATTACH:
		printf("Process attached \n");
		break;
	case DLL_PROCESS_DETACH:
		printf("Process detached.\n");
		break;
	}
	return TRUE;
}
int add1(int x, int y) {
	return x + y;
}
int sub1(int x, int y) {
	return x - y;
}
int mul1(int x, int y) {
	return x*y;
}
int div1(int x, int y) {
	return x / y;
}