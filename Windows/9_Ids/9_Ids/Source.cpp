#include<stdio.h>
#include<windows.h>
#include<tchar.h>
#include<shellapi.h>
DWORD WINAPI threadfunc(LPVOID lparam) {
	printf("entered into thread\n");
	Sleep(2000);
	printf("Current process id in Thraed function: %ld\n", GetCurrentProcessId());
	printf("Current thread Id in Thraed function :%ld", GetCurrentThreadId());

	return 0;
}
int main() {
	printf("Current Process Id is: %ld", GetCurrentProcessId());
	printf("Current Thread Id is :%ld", GetCurrentThreadId());
	DWORD dwThread;
	HANDLE hThread;
	getchar();
	hThread = CreateThread(NULL, 0, threadfunc, NULL, 0, &dwThread);
	getchar();
	if (hThread == NULL) {
		printf("unable to create thread Error: %d\n", GetLastError());
		return -1;
	}

	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	HANDLE hproc;
	//LPSTR proc ="NOTEPAD";
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	getchar();
	if (!CreateProcess(NULL,TEXT("NOTEPAD"), NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
	{
		_tprintf(_T("Creation of a process failed error:%d"), GetLastError());
		getchar();
		return -1;
	}
	else {
		getchar();
		printf("%d\n", pi.hProcess);
		printf("%d\n", pi.dwProcessId);
		printf("id of process %ld", GetProcessId(pi.hProcess));
		CloseHandle(pi.hThread);
		CloseHandle(pi.hProcess);
	}

	printf("id of thread %ld\n", GetThreadId(hThread));
	CloseHandle(hThread);

	system("pause");
	return 0;
}