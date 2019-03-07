
#include<Windows.h>

#include<stdio.h>

#define MAX_SEM_COUNT 1

#define THREAD_COUNT 4

HANDLE ghSemaphore;

DWORD WINAPI ThreadProc(LPVOID);

int main()

{

	HANDLE aThread[THREAD_COUNT];

	DWORD dwThID;



	ghSemaphore = CreateSemaphore(NULL, MAX_SEM_COUNT, MAX_SEM_COUNT, NULL);

	if (NULL == ghSemaphore)

	{

		printf("\n semaphore creation error %d", GetLastError());

		getchar();

		return FALSE;

	}

	for (int i = 0; i < THREAD_COUNT; i++)

	{

		aThread[i] = CreateThread(NULL, 0, ThreadProc, NULL, 0, &dwThID);

		if (NULL == aThread[i])

		{

			printf("\n thread %d creation error %d", i, GetLastError());

			getchar();

			return FALSE;

		}

	}

	WaitForMultipleObjects(THREAD_COUNT, aThread, TRUE, INFINITE);

	for (int i = 0; i < THREAD_COUNT; i++)

	{

		CloseHandle(aThread[i]);

	}

	CloseHandle(ghSemaphore);

	getchar();

	return 0;

}

DWORD WINAPI ThreadProc(LPVOID lppar)

{

	UNREFERENCED_PARAMETER(lppar);

	DWORD dwRes;

	BOOL b = TRUE;

	while (b)

	{

		dwRes = WaitForSingleObject(ghSemaphore, INFINITE);

		switch (dwRes)

		{

		case WAIT_OBJECT_0:

			printf("\n the thread %d wait is sucessful", GetCurrentThreadId());

			b = FALSE;

			Sleep(20000);

			if (!ReleaseSemaphore(ghSemaphore, 1, NULL))

			{

				printf("\n release semaphore error");



			}

			break;

		case WAIT_TIMEOUT:

			printf("\n thread %d wait timeout ", GetCurrentThreadId());

			break;



		}

	}

	return TRUE;

}