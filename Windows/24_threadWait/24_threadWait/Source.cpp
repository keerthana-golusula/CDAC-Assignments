#include<stdio.h>
#include<windows.h>
#include<tchar.h>
#include<shellapi.h>
DWORD exitCode = 0;
DWORD WINAPI threadfunc(LPVOID lparam) {

	printf("entered into thread\n");
	Sleep(2000);
	for (int i = 0; i < 10; i++) {
		printf("i=%d\n", i);
		Sleep(1000);
	}
	return 0;
}


int main() {
	DWORD dwThread;
	HANDLE hThread;
	//DWORD exitCode = 0;
	hThread = CreateThread(NULL, 0, threadfunc, NULL, 0, &dwThread);
	if (hThread == NULL) {
		printf("unable to create thread Error: %d\n", GetLastError());
		return -1;
	}
	//WaitForSingleObject(hThread, INFINITE);
	//WaitForSingleObject(hThread, 1000);
	WaitForSingleObject(hThread, 1000);
//etExitCodeThread(hThread, &exitCode);
	//printf("exitcode is :%d", exitCode);
	if (CloseHandle(hThread))
	{
		printf("Handle closed");
	}


	//CloseHandle(hThread);
	system("pause");
}