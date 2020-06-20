#include<text.hpp>

//for windows
uint8_t Text::init(int8_t *filename){	
	HANDLE hFile;

	hFile = CreateFile((LPCWSTR)filename, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, 0, 0);
	if (hFile == INVALID_HANDLE_VALUE)
		return 1;

	return inithFile(hFile);
}

uint8_t Text::inithFile(HANDLE hFile){
	uint64_t numread;
	if (length = GetFileSize(hFile, 0) == 0)
		return false;
	if ((buffer = new int8_t[length]) == 0)
		return 0;
	ReadFile(hFile, buffer, length, (LPDWORD)&numread, 0);

	init_linebuffer();
	CloseHandle(hFile);
	return 0;
}