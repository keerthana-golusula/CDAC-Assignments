#include<stdio.h>
#include<windows.h>
#include<shellapi.h>
int main() {
	LPWSTR *sarglist;
	int nargs;
	int i;
	sarglist = CommandLineToArgvW(GetCommandLine(), &nargs);
	if (NULL == sarglist)
	{
		wprintf(L"failed");
		return -1;
	}
	else
	{
		for (i = 1 ; i < nargs; i++)
			printf("%d:%S\n", i, sarglist[i]);
	}
	system("pause");
	return 0;


}