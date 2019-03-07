#include<stdio.h>
#include<windows.h>
#include<tchar.h>
#include<shellapi.h>
//DWORD exitCode = 0;
DWORD WINAPI threadfunc(LPVOID lparam) {
	
	printf("entered into thread\n");
	Sleep(4000);
	printf("waited");
	/*for (int i = 0; i < 10; i++) {
		printf("1i=%d\n", i);
		Sleep(1000);
	}*/

	return 0;
}
DWORD WINAPI threadfunc1(LPVOID lparam) {
	
	printf("entered into thread2\n");
	Sleep(3000);
	printf("waited2");
	/*for (int i = 0; i < 10; i++) {
		printf("2i=%d\n", i);
		Sleep(1000);
	}*/
	return 0;
}


int main() {
	DWORD dwThread,dwThread2;
	HANDLE hThread,hThread2;
	HANDLE arrThread[2];
	//DWORD exitCode = 0;
	hThread = CreateThread(NULL, 0, threadfunc, NULL, 0, &dwThread);
	if (hThread == NULL) {
		printf("unable to create thread Error: %d\n", GetLastError());
		return -1;
	}
	hThread2 = CreateThread(NULL, 0, threadfunc1, NULL, 0, &dwThread2);
	if (hThread2 == NULL) {
		printf("unable to create thread Error: %d\n", GetLastError());
		return -1;
	}
	arrThread[0] = hThread;
	arrThread[1] = hThread2;
//	WaitForMultipleObjects(2,arrThread,TRUE, INFINITE);
	WaitForMultipleObjects(2, arrThread, FALSE, 2000);
	//GetExitCodeThread(hThread, &exitCode);
	//printf("exitcode is :%d", exitCode);
	if (CloseHandle(hThread))
	{
		printf("Handle closed");
	}


	//CloseHandle(hThread);
	system("pause");
}