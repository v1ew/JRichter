#include <Windows.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	DWORD dwError = 0;
	HLOCAL hLocal = NULL;

	if (argc > 1)
		dwError = atoi(argv[1]);

	BOOL fOk = FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER, NULL, dwError,
		MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US), (LPTSTR)&hLocal, 0, NULL);
	if (hLocal != NULL) {
		printf("%S\n", (PCTSTR)hLocal);
		LocalFree(hLocal);
	}
	return 0;
}
