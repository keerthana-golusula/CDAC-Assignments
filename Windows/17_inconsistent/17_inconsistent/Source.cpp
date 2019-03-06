#include<stdio.h>
#include<windows.h>
#include<tchar.h>
LONG x = 1;
DWORD WINAPI ThreadFunc1(LPVOID lparam) {
	while (1) {
		//x = x++;
		InterlockedAdd(&x, 1);
		printf("Thread1 x=:%d\n", x);
		Sleep(500);

	}
}
DWORD WINAPI ThreadFunc2(LPVOID lparam) {
	while (1) {
		//x = x++;
		InterlockedAdd(&x, 1);
		printf("Thread2 x=:%d\n", x);
		Sleep(500);
	}

}

int main() {
	DWORD dwThread1, dwThread2,exitCode1=0,exitcode2=0;
	HANDLE hThread1, hThread2;
	hThread1 = CreateThread(NULL, 0, ThreadFunc1, NULL, 0, &dwThread1);
	hThread2 = CreateThread(NULL, 0, ThreadFunc2, NULL, 0, &dwThread2);
	if (hThread1 == NULL) {
		printf("thread1 not created: Error:%d", GetLastError());
		getchar();
		return -1;
	}
	if (hThread2 == NULL) {
		printf("thread1 not created: Error:%d", GetLastError());
		getchar();
		return -1;
	}
	printf("enter any character to break threads\n");
	getchar();
	
	TerminateThread(hThread1, exitCode1);
	TerminateThread(hThread2, exitcode2);
	//getchar();
	CloseHandle(hThread1);
	CloseHandle(hThread2);
	//getchar();
	system("pause");
	return 0;


}