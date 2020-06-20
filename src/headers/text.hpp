#ifndef TEXT_HPP
#define TEXT_HPP
#include <cstdint>
//for windows
#include<windows.h>

class Text {
public:
	uint8_t init(int8_t *fliename);
	uint8_t inithFile(HANDLE hFile);

	uint64_t getline(uint64_t lineno, uint8_t* buf, uint32_t len);
	uint64_t linecount();
private:
	bool init_linebuffer();
	int8_t* buffer;
	uint32_t length;
};


#endif // !TEXT_HPP
