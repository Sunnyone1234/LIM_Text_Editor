#ifndef TEXTVIEW_HPP
#define TEXTVIEW_HPP

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

typedef struct { 
	wxColor fc;
	wxColor bc;
	uint64_t style;
} Prop;

typedef struct {
	wxFont font;
	//TODO: maybe define some Textmetric here?
} Font;

class TextView {

public:
	TextView() {}
	~TextView() {}

private:
	uint32_t ApplyTextProperty(uint64_t nLine, uint64_t nOffset, uint8_t* sText, uint32_t tLenth, Prop* prop) {
	}
	
	uint64_t TabWidthChars;//TODO:use for what?
	uint64_t selectionStart;
	uint64_t selectionEnd;
};

#endif // !TEXTVIEW_HPP