#include "main.hpp"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    if (!wxApp::OnInit())
        return false;

    MyFrame* frame = new MyFrame("Minimal wxWidgets App");

    frame->Show(true);

    return true;
}


MyFrame::MyFrame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title)
{
    SetIcon(wxICON(sample));

    wxMenu* fileMenu = new wxMenu;

    wxMenu* helpMenu = new wxMenu;
    fileMenu->Append(EDITOR_New, "&New\tCtrl+n", "New a note");
    fileMenu->Append(EDITOR_Save, "&Save\tCtrl+s", "Save a note");
    fileMenu->Append(EDITOR_SaveAs, "&Save As\tCtrl+Alt+s", "Save a note as");
    fileMenu->Append(EDITOR_Quit, "&Exit\tCtrl+q", "Quit this program");
    helpMenu->Append(EDITOR_About, "&About\tF1", "Show about dialog");

    wxMenuBar* menuBar = new wxMenuBar();
    menuBar->Append(fileMenu, "&File");
    menuBar->Append(helpMenu, "&Help");

    SetMenuBar(menuBar);
}

void MyFrame::OnNew(wxCommandEvent& WXUNUSED(event)){}
void MyFrame::OnSave(wxCommandEvent& WXUNUSED(event)) {}
void MyFrame::OnSaveAs(wxCommandEvent& WXUNUSED(event)) {}
void MyFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
    Close(true);
}

void MyFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
    wxMessageBox(wxT("The LIM_TEXT_EDITOR is a cross-plattform Text Editor entwickelt with CMake."),
        "About LIM_Text_Editor",
        wxOK | wxICON_INFORMATION,
        this);
}
