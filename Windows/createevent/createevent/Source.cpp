#include<stdio.h>
#include<windows.h>
#include<tchar.h>
int main(int argc,LPSTR argv[]) {
	HANDLE ghEvent = CreateEvent(NULL, FALSE, FALSE, TEXT("namedEvent"));
	if (!ghEvent) {
		printf("Error in creating Event:%d", GetLastError());
		return -1;
	}

	//CloseHandle(ghEvent);
	getchar();
	return 0;
}