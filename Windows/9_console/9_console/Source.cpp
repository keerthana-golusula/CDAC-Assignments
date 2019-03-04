#include<stdio.h>
#include<windows.h>
#include<tchar.h>
#define BUFFSIZE 100
int main(int argc,LPTSTR argv[]) {
	if (argc != 2)
		printf("error:%d",GetLastError());
	struct _SECURITY_ATTRIBUTES sec;
	sec.nLength = 0;
	sec.lpSecurityDescriptor = NULL;
	sec.bInheritHandle = TRUE;
	HANDLE hFile = CreateFile(_T("file.txt"), GENERIC_ALL,0,&sec, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE) {
		_tprintf(_T("file doesnot exist:%d\n"), GetLastError());
		getchar();
		return -1;
	}

	_tprintf(_T("file %S opened successfully"),  argv[1]);
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	printf("hFile:%p", hFile);
	if (CreateProcess(TEXT("C:/Users/cdac/Desktop/assignments/Ncrwork-CDAC-Assignments/Windows/9_console/Debug/process.exe"), (LPTSTR)&hFile, NULL, NULL, TRUE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi)) {
		getchar();
		printf("opened process successfully\n");
		printf("%d\n", pi.hProcess);
		printf("%d\n", pi.dwProcessId);

		CloseHandle(pi.hThread);
		CloseHandle(pi.hProcess);
		getchar();
	}
	else {
		printf("cannot create process Error:%d", GetLastError());
		getchar();
		return -1;
	}
	getchar();
	system("pause");
}