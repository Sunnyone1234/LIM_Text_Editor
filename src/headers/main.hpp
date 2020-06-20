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

#endif // !MAIN_HPP
