#include<stdio.h>
#include<windows.h>
#include<tchar.h>
#include<shellapi.h>
void DumpEnvString(PTSTR penvblock[]) {
	int curr = 0;
	PTSTR *pe = (PTSTR *)penvblock;
	PTSTR pcurr = NULL;
	while (pe != NULL) {
		pcurr = (PTSTR)(*pe);
		if (pcurr == NULL)
			pe = NULL;
		else {
			_tprintf(TEXT("[%u]%S\r\n"), curr, pcurr);
			curr++;
			pe++;
		}
	}
}
int main(int argc, TCHAR *argv[], TCHAR *env[]) {
	DumpEnvString(env);
	TCHAR envVarString[] = TEXT("%SYSTEMROOT%");
	TCHAR buffer[MAX_PATH];
	DWORD ret;
	ret = ExpandEnvironmentStrings(envVarString, buffer, MAX_PATH);
	if (!ret) {
		printf("hello");
		printf("%d\n", GetLastError());
		getchar();
		return -1;
	}
	else
		printf("%S\n", buffer);

	system("pause");
}
