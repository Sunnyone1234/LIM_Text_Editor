#ifndef TEXT_HPP
#define TEXT_HPP
#include <cstdint>
//for windows
#include<windows.h>

class Text {
public:
	Text();
	~Text();

	bool init(int8_t *fliename);
	bool inithFile(HANDLE hFile);
	bool clear();

	uint64_t getline(uint64_t lnr, int8_t* buf, uint64_t len);
	uint64_t linecount();
	uint64_t longestline();
private:
	bool init_linebuffer();
	int8_t* buffer;
	uint64_t* linebuffer;
	uint64_t length;
	uint64_t linenr;
};


#endif // !TEXT_HPP
