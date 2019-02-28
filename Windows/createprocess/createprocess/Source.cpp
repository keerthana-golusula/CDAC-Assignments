#include<stdio.h>
#include<windows.h>
#include<tchar.h>
#include<shellapi.h>
int main(int argc, LPTSTR argv[]) {
	STARTUPINFO si,si2;
	PROCESS_INFORMATION pi,pi2;
	HANDLE hproc;
	//LPSTR proc ="NOTEPAD";
	if (argc != 3) {
		printf("usage filename.exe <process1> <process2>");
		return -1;
  }
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	if (!CreateProcess(NULL,argv[1], NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
	{
		_tprintf(_T("Creation of a process failed error:%d"), GetLastError());
		getchar();
		return -1;
	}
	else {
		printf("%d\n", pi.hProcess);
		printf("%d\n", pi.dwProcessId);
		CloseHandle(pi.hThread);
		CloseHandle(pi.hProcess);
	}

	ZeroMemory(&si2, sizeof(si2));
	si2.cb = sizeof(si2);
	ZeroMemory(&pi2, sizeof(pi2));
	if (!CreateProcess(NULL, argv[2], NULL, NULL, FALSE, 0, NULL, NULL, &si2, &pi2))
	{
		_tprintf(_T("Creation of a process failed error:%d"), GetLastError());
		getchar();
		return -1;
	}
	else {
		printf("%d\n", pi2.hProcess);
		printf("%d\n", pi2.dwProcessId);
		/*DWORD dwRet = WaitForSingleObject(pi.hProcess, INFINITE);
		printf(" %d\n", dwRet);*/
		CloseHandle(pi2.hThread);
		CloseHandle(pi2.hProcess);
	}
	getchar();
	return 0;
}