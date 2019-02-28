#include<stdio.h>
#include<windows.h>
#include<tchar.h>
#include<shellapi.h>
#define BUFFSIZE 100
int main(int argc,LPTSTR argv[]) {
	HANDLE hFile;
	TCHAR buffer[BUFFSIZE];
	if (argc != 2) {
		printf("usage: filename.exe <anotherfile name to be opened>");
		getchar();
		return -1;
	}
	//printf("%s",argv[1]);
	hFile = CreateFile(argv[1], GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE) {
		_tprintf(_T("File doesnot exist,Error:%d\n"), GetLastError());
		getchar();
		return -1;
	}
	_tprintf(_T("file (%S) opened successfully\n"), argv[1]);
	DWORD nbr;
	ZeroMemory(buffer, BUFFSIZE);
	BOOL ret = ReadFile(hFile, buffer, BUFFSIZE, &nbr, NULL);
	if (ret == 0) {
		_tprintf(_T("cant read File.Error (%d)\n"), GetLastError());
		getchar();
		return -1;
	}
	
	CloseHandle(hFile);
	_tprintf(_T("Text from (%s) %s\n"), argv[1], buffer);
	getchar();
	return 0;
}

