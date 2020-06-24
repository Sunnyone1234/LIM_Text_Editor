#ifndef VIEW_HPP
#define VIEW_HPP
#include <wx/wx.h>
#include <main.hpp>

class EDITOR_Panel : public wxPanel {
public:
	EDITOR_Panel(wxFrame* parent);
	void paintEvent(wxPaintEvent& evt);
	void paintNow();
	void render(wxDC& dc);

	//some event handler

};
#endif // !VIEW_HPP
