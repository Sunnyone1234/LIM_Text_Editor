#ifndef VIEW_HPP
#define VIEW_HPP

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

class EditorFrame : public wxFrame
{
public:
    EditorFrame(const wxString& title);

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

class EditorPanel : public wxPanel {
public:
    EditorPanel(wxFrame* parent);
    void paintEvent(wxPaintEvent& evt);
    void paintNow();
    void render(wxDC& dc);

    //some event handler

};

class EditorScrollWindow : public wxScrolledWindow {
public:
    EditorScrollWindow(wxPanel* EditorPanel);
};

#endif // !VIEW_HPP
