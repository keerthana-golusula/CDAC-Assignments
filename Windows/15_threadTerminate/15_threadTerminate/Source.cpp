#include<stdio.h>
#include<Windows.h>
#include<tchar.h>
#include<shellapi.h>
DWORD WINAPI Threadfunc(LPVOID lparam) {
	for (int i = 0; i < 10; i++)
	{
		printf("i=%d\n", i);
		Sleep(500);
	}
	return 0;
}
int main() {
	DWORD dwthread;
	HANDLE hThread;
	DWORD dwExitCode=0;
	hThread = CreateThread(NULL, 0, Threadfunc, NULL, 0, &dwthread);
	if (hThread == NULL) {

		printf("unable to create thread Error:%d\n", GetLastError());
		return -1;
	}
	printf("to break the thread press any character\n");
	getchar();
	//WaitForSingleObject(hThread, INFINITE);
	GetExitCodeThread(hThread, &dwExitCode);
	if (dwExitCode == STILL_ACTIVE) {
		BOOL ret = TerminateThread(hThread, dwExitCode);
		if (ret != 0) {
			printf("thread terminated successfully");
			GetExitCodeThread(hThread, &dwExitCode);
			printf("Exit Code is %d", dwExitCode);
		}
	}
	CloseHandle(hThread);
	system("pause");
	return 0;
}