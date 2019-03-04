#include<stdio.h>
#include<windows.h>
#include<tchar.h>
#include<shellapi.h>
DWORD exitCode = 0;
DWORD WINAPI threadfunc(LPVOID lparam) {
	
	printf("entered into thread\n");
	for (int i = 0; i < 10; i++) {
		printf("i=%d\n", i);
		Sleep(1000);
	}
	ExitThread(exitCode);
	printf("Thread closed");
	
	return 0;
}


int main() {
	DWORD dwThread;
	HANDLE hThread;
	//DWORD exitCode = 0;
	hThread = CreateThread(NULL, 0, threadfunc, NULL,0, &dwThread);
	if (hThread == NULL) {
		printf("unable to create thread Error: %d\n", GetLastError());
		return -1;
	}
	WaitForSingleObject(hThread, INFINITE);
	GetExitCodeThread(hThread, &exitCode);
	printf("exitcode is :%d", exitCode);
		if (CloseHandle(hThread))
		{
			printf("Handle closed");
		}
	

	//CloseHandle(hThread);
	system("pause");
}