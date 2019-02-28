#include<stdio.h>
#include<windows.h>
#include<tchar.h>
#include<shellapi.h>
int main(int argc,LPWSTR argv[]) {
	printf("entered into process.exe");
	HANDLE hfile = (HANDLE)argv[1];
	if (argc != 2) {
		printf("");
		return -1;
	}
	TCHAR buffer[] =TEXT("this is text from child process");
	DWORD dwnbr;
	BOOL ret = WriteFile(hfile, buffer, sizeof(buffer), &dwnbr, NULL);
	if (ret == 0) {
		printf("cant write the file Error:%d\n", GetLastError());
		getchar();
		return -1;

	}
	system("pause");
}