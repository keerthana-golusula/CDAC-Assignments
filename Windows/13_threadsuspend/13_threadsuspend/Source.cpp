#include<stdio.h>
#include<windows.h>
#include<tchar.h>
#include<shellapi.h>
DWORD WINAPI threadfunc(LPVOID lparam) {
	printf("entered into thread\n");
	for (int i = 0; i < 10; i++) {
		printf("i=%d\n", i);
		Sleep(1000);
	}
	return 0;
}


int main() {
	DWORD dwThread;
	HANDLE hThread;
	hThread = CreateThread(NULL, 0, threadfunc, NULL, CREATE_SUSPENDED, &dwThread);
	if (hThread == NULL) {
		printf("unable to create thread Error: %d\n", GetLastError());
		return -1;
	}
	else {
		printf("thread created\n");
		Sleep(5000);
		ResumeThread(hThread);
		getchar();
		//printf("thread is resumed\n");
	}
	CloseHandle(hThread);
	system("pause");
}