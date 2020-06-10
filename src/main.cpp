#include <iostream>
#include "headerfiles/headers.hpp"


wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
	if (!wxApp::OnInit())
		return false;
	MyFrame* frame = new MyFrame("Minimal wxWigets App");
	frame->Show(true);
	return true;
}

MyFrame::MyFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title) {
	//SetIcon(wxIcon());
//#if wxUSE_MENUS
	wxMenu* fileMenu = new wxMenu;
	wxMenu* aboutMenu = new wxMenu;
	fileMenu->Append(wxID_NEW, "&New\tCtrl-n", "New a note");
	fileMenu->Append(wxID_OPEN, "&Open\tCtrl-o", "Open a note");
	fileMenu->Append(wxID_SAVE, "&Save\tCtrl-s", "Save a note");
	fileMenu->Append(wxID_SAVEAS, "&Save As\tCtrl-Alt-s", "Save a note as");
	fileMenu->AppendSeparator();
	fileMenu->Append(wxID_EXIT, "&Exit\tAlt-Q", "Quit this program ");
	aboutMenu->Append(wxID_ABOUT, "&About\tAlt-h", "Show about dialog");


	wxMenuBar* menuBar = new wxMenuBar();
	menuBar->Append(fileMenu, "&File");
	menuBar->Append(aboutMenu, "&About");
	SetMenuBar(menuBar);
	CreateStatusBar();
	SetStatusText(wxT("LIM_TEXT_EDITOR ready"));
}

void MyFrame::OnQuit(wxCommandEvent& WXUNUSED(event)) {
	Close(true);
}

void MyFrame::OnAbout(wxCommandEvent& WXUNUSED(event)) {
	wxMessageBox(wxT
	("Welcome to LIM_TEXT_EDITOR AUTHOR YIZE"
	),
		"About LMI_TEXT_EDITOR",
		wxOK | wxICON_INFORMATION,
		this);
}