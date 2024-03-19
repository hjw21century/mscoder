// multithread_locale_2.cpp
// compile with: /EHsc /MD
#include <clocale>
#include <cstdio>
#include <locale>
#include <process.h>
#include <windows.h>

#define NUM_THREADS 2
using namespace std;

unsigned __stdcall RunThreadA(void *params);
unsigned __stdcall RunThreadB(void *params);

BOOL localeSet = FALSE;
HANDLE printMutex = CreateMutex(NULL, FALSE, NULL);

int main()
{
	HANDLE threads[NUM_THREADS];

	unsigned aID;
	threads[0] = (HANDLE)_beginthreadex(
		NULL, 0, RunThreadA, NULL, 0, &aID);

	unsigned bID;
	threads[1] = (HANDLE)_beginthreadex(
		NULL, 0, RunThreadB, NULL, 0, &bID);

	WaitForMultipleObjects(2, threads, TRUE, INFINITE);

	printf_s("[Thread main] Per-thread locale is NOT enabled.\n");
	printf_s("[Thread main] CRT locale is set to \"%s\"\n",
		setlocale(LC_ALL, NULL));
	printf_s("[Thread main] locale::global is set to \"%s\"\n",
		locale().name().c_str());

	CloseHandle(threads[0]);
	CloseHandle(threads[1]);
	CloseHandle(printMutex);

	return 0;
}

unsigned __stdcall RunThreadA(void *params)
{
	_configthreadlocale(_ENABLE_PER_THREAD_LOCALE);
	locale::global(locale("french"));
	localeSet = TRUE;

	WaitForSingleObject(printMutex, INFINITE);
	printf_s("[Thread A] Per-thread locale is enabled.\n");
	printf_s("[Thread A] CRT locale is set to \"%s\"\n",
		setlocale(LC_ALL, NULL));
	printf_s("[Thread A] locale::global is set to \"%s\"\n\n",
		locale().name().c_str());
	ReleaseMutex(printMutex);

	return 1;
}

unsigned __stdcall RunThreadB(void *params)
{
	while (!localeSet)
		Sleep(100);

	WaitForSingleObject(printMutex, INFINITE);
	printf_s("[Thread B] Per-thread locale is NOT enabled.\n");
	printf_s("[Thread B] CRT locale is set to \"%s\"\n",
		setlocale(LC_ALL, NULL));
	printf_s("[Thread B] locale::global is set to \"%s\"\n\n",
		locale().name().c_str());
	ReleaseMutex(printMutex);

	return 1;
}