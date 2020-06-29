#include "textview.hpp"

TextView::TextView(){}

uint32_t TextView::ApplyTextProperty(uint64_t nLine, uint64_t nOffset, uint8_t* sText, uint32_t tLenth, Prop* prop){

	for (uint64_t i = 0; i < tLenth; i++) {
		if (nOffset + i >= selectionStart && nOffset + i < selectionEnd) {
			prop[i].fc = wxT("foreground color");
			prop[i].bc = wxT("background color");
		}
		else {
			prop[i].fc = wxT("foreground color");
			prop[i].bc = wxT("background color");
		}
		prop[i].style = 0;
	}

	return 0;//TODO: return something
}