// child process

#include<stdio.h>
#include<windows.h>
#include<tchar.h>
DWORD WINAPI threadfunc(LPVOID lparam) {
	printf("entered into thread\n");
	for (int i = 0; i < 10; i++) {
		printf("i=%d\n", i);
		Sleep(1000);
	}
	return 0;
}
int main(int argc, LPWSTR argv[]) {
	if (argc != 1)
	{
		printf("Usage: file.exe argument");
		getchar();
		return -1;
	}
	printf("entered into child process");
	getchar();
	printf("%ld", argv[0]);
	HANDLE hProc = (HANDLE)(*argv[0]);
	printf("%ld", hProc);
	BOOL ret = SetPriorityClass(hProc, BELOW_NORMAL_PRIORITY_CLASS);
	if (ret == 0) {
		printf("priority set failed Error:%d", GetLastError());
		getchar();
		//return -1;
	}
	DWORD dwThread;
	HANDLE hThread;
	getchar();
	hThread = CreateThread(NULL, 0, threadfunc, NULL, 0, &dwThread);
	getchar();
	if (hThread == NULL) {
		printf("unable to create thread Error: %d\n", GetLastError());
		return -1;
	}
	printf("Current thread Priority is %d",GetThreadPriority(hThread));
	SetThreadPriority(hThread, THREAD_PRIORITY_LOWEST);
	printf("After Changing, thread Priority is %d", GetThreadPriority(hThread));
	CloseHandle(hThread);


	system("pause");
}