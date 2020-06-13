#ifndef MAIN_HPP
#define MAIN_HPP

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

class MyApp : public wxApp
{
public:
    virtual bool OnInit() wxOVERRIDE;
};

class MyFrame : public wxFrame
{
public:
    MyFrame(const wxString& title);

    //create Event Handler
    void OnNew(wxCommandEvent& event);
    void OnSave(wxCommandEvent& event);
    void OnSaveAs(wxCommandEvent& event);
    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

private:
    wxDECLARE_EVENT_TABLE();
};

//enum Button ID
enum
{
    EDITOR_New = wxID_NEW,
    EDITOR_Save = wxID_SAVE,
    EDITOR_SaveAs = wxID_SAVEAS,
    EDITOR_Quit = wxID_EXIT,
    EDITOR_About = wxID_ABOUT
};

//Add Button ID in Event Table
wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
EVT_MENU(EDITOR_New, MyFrame::OnNew)
EVT_MENU(EDITOR_Save, MyFrame::OnSave)
EVT_MENU(EDITOR_SaveAs, MyFrame::OnSaveAs)
EVT_MENU(EDITOR_Quit, MyFrame::OnQuit)
EVT_MENU(EDITOR_About, MyFrame::OnAbout)
wxEND_EVENT_TABLE()

#endif // !MAIN_HPP
