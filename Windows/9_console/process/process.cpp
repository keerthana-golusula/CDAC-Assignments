#include<stdio.h>
#include<windows.h>
#include<tchar.h>
#include<shellapi.h>
int main(int argc,LPWSTR argv[]) {
	getchar();
	printf("entered into process.exe");
	getchar();
	HANDLE hfile = (HANDLE)*argv[0];
	printf("hFile:%p", hfile);
	getchar();

	//printf("%S", argv[1]);
	getchar();
	TCHAR buffer[] =TEXT("this is text written from child process");
	DWORD dwnbr;
	printf("continue\n");
	BOOL ret = WriteFile(hfile, buffer, sizeof(buffer), &dwnbr, NULL);
	if (ret == 0) {
		printf("cant write the file Error:%d\n", GetLastError());
		getchar();
		return -1;

	}
	else {
		printf("written\n");
	}
	system("pause");
}