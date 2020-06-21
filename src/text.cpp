#include<text.hpp>
Text::Text() {
	buffer = 0;
	length = 0;
	linebuffer = 0;
	linenr = 0;
}
Text::~Text() {
	clear();
}
//for windows
bool Text::init(int8_t *filename){	
	HANDLE hFile;

	hFile = CreateFile((LPCWSTR)filename, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, 0, 0);
	if (hFile == INVALID_HANDLE_VALUE)
		return 1;

	return inithFile(hFile);
}

bool Text::inithFile(HANDLE hFile){
	uint64_t numread;
	if (length = GetFileSize(hFile, 0) == 0)
		return false;
	if ((buffer = new int8_t[length]) == 0)
		return 0;
	//TODO: convert uint64_t to (LPDWORD) may lose data
	ReadFile(hFile, buffer, length, (LPDWORD)&numread, 0);

	init_linebuffer();
	CloseHandle(hFile);
	return 0;
}

bool Text::init_linebuffer() {
	uint64_t linestart = 0;
	if ((linebuffer = new uint64_t[length]) == 0)
		return false;
	linenr = 0;
	for (uint64_t i = 0; i < length;i++) {
		if (buffer[i] == '\r') {
			if (buffer[++i] == '\n')
			linebuffer[linenr++] = linestart;
			linestart = ++i;
		}
	}
	if (length > 0)
		linebuffer[linenr++] = linestart;
	
	linebuffer[linenr] = length;
	return true;

}

bool Text::clear() {
	if (buffer) {
		delete buffer;
		buffer = 0;
		length = 0;
	}

	if (linebuffer) {
		delete linebuffer;
		linebuffer = 0;
		linenr = 0;
	}

	return true;
}

uint64_t Text::getline(uint64_t lnr, int8_t* buf, uint64_t len) {
	int8_t* lptr;
	uint64_t llen;
	if (lnr >= linenr || buffer == 0 || length == 0)
		return 0;
	lptr = buffer + linebuffer[lnr];
	llen = linebuffer[lnr + 1] - linebuffer[lnr];
	llen = min(llen, len);
	memcpy(buf, lptr, llen);

	return llen;
}

uint64_t Text::linecount() {
	return linenr;
}

uint64_t Text::longestline() {
	uint64_t templen = 0;
	uint64_t longest = 0;
	for (uint32_t i = 0; i < linenr; i++) {
		templen = linebuffer[i + 1] - linebuffer[i];
		if (templen > longest) longest = templen;
	}
	return longest;
}