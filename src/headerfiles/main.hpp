#ifndef MAIN_HPP
#define MAIN_HPP

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

class MyApp : public wxApp {
public:
	virtual bool OnInit() wxOVERRIDE;
};

class MyFrame : public wxFrame {
public:
	MyFrame(const wxString& title);
	void OnQuit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
	void OnNew(wxCommandEvent& event);

private:
	wxDECLARE_EVENT_TABLE();
};
#endif