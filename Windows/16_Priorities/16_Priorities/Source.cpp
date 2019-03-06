#include<stdio.h>
#include<windows.h>
#include<tchar.h>
#include<shellapi.h>
int main() {

	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	//printf("hFile:%p", hFile);
	static LPTSTR str2;
	str2 = (LPTSTR)&pi.hProcess;
	/*WCHAR *str;
	str =(WCHAR)&pi.hProcess;*/
	printf("%d ", str2);
	if (CreateProcess(TEXT("C:/Users/cdac/Desktop/assignments/Ncrwork-CDAC-Assignments/Windows/16_Priorities/Debug/childProcess.exe"),str2, NULL, NULL, TRUE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi)) {
		//str = (WCHAR)&pi.hProcess;
		printf("%d ", str2);
		printf("%p ", (HANDLE)*str2);
		BOOL ret = SetPriorityClass(pi.hProcess, HIGH_PRIORITY_CLASS);
		printf("Current Priority of child process is %d", GetPriorityClass(pi.hProcess));
		printf("%p", pi.hProcess);
		if (ret==0)
		{
			printf("priority didnot set Error:%d", GetLastError());
			getchar();
			return -1;
		}
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





	system("pause");


 }


