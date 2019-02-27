#include<stdio.h>
#include<windows.h>
#include<tchar.h>
#include<shellapi.h>
void main(int argc,LPTSTR argv[]) {
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	HANDLE hproc;
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	if (!CreateProcess(NULL, argv[1], NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
	{
		_tprintf(_T("Creation of a process failed error:%d"), GetLastError());
		getchar();
		return -1;
	}
	else {
		printf("%d", pi.hProcess);
		printf("%d", pi.dwProcessId);
	}

}