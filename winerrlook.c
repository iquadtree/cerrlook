#include <stdio.h>
#include <stdlib.h>

#include <windows.h>

int main(int argc, char *argv[])
{
    if (argc < 2) {
		puts("usage: winerrlook [MODULE]... CODE");

		return EXIT_SUCCESS;
	}
	
	unsigned int code = strtoul(argv[argc - 1], NULL, 0);
	char * module_name = "<system>";
	int modules = argc - 2;
	char msg[65535] = {0};
	
	DWORD res = 0, flags = FORMAT_MESSAGE_FROM_SYSTEM;
	HMODULE hm = INVALID_HANDLE_VALUE;

	res = FormatMessageA(FORMAT_MESSAGE_FROM_SYSTEM, NULL, HRESULT_CODE(code), 0, msg, sizeof(msg), NULL);
	for (int i = 0; i < modules && res == 0; i++) {
		hm = LoadLibraryA(argv[i + 1]);
		module_name = argv[i + 1];
		res = FormatMessageA(FORMAT_MESSAGE_FROM_HMODULE | FORMAT_MESSAGE_FROM_SYSTEM, hm, HRESULT_CODE(code), 0, msg, sizeof(msg), NULL);
		FreeLibrary(hm);
	}
	
	if (!res) {
		printf("Can't get message for code '%s': 0x%08X\n", argv[argc - 1], GetLastError());
		return EXIT_FAILURE;
	}
	
	printf("Dec:\t%d\n", code);
	printf("Hex:\t0x%08X\n", code);
	printf("Module:\t%s\n", module_name);
	printf("Text:\t%s\n", msg);

	return EXIT_SUCCESS;
}