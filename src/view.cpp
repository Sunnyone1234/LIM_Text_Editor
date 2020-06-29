#include "view.hpp"

EditorFrame::EditorFrame(const wxString& title)
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

    //bind eventhandler
    Bind(wxEVT_COMMAND_MENU_SELECTED, &EditorFrame::OnQuit, this, EDITOR_Quit);
    Bind(wxEVT_COMMAND_MENU_SELECTED, &EditorFrame::OnAbout, this, EDITOR_About);
    Bind(wxEVT_COMMAND_MENU_SELECTED, &EditorFrame::OnNew, this, EDITOR_New);
    Bind(wxEVT_COMMAND_MENU_SELECTED, &EditorFrame::OnSave, this, EDITOR_Save);
    Bind(wxEVT_COMMAND_MENU_SELECTED, &EditorFrame::OnSaveAs, this, EDITOR_SaveAs);

}

void EditorFrame::OnNew(wxCommandEvent& WXUNUSED(event)) {//TODO::
}
void EditorFrame::OnSave(wxCommandEvent& WXUNUSED(event)) {//TODO::
}
void EditorFrame::OnSaveAs(wxCommandEvent& WXUNUSED(event)) {//TODO::
}
void EditorFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
    Close(true);
}

void EditorFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
    wxMessageBox(wxT("The LIM_TEXT_EDITOR is a cross-plattform Text Editor entwickelt with CMake."),
        "About LIM_Text_Editor",
        wxOK | wxICON_INFORMATION,
        this);
}

EditorScrollWindow::EditorScrollWindow(wxPanel* mainPanel)
    : wxScrolledWindow(mainPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxVSCROLL) {//only vertical roll for text editor
}

EditorPanel::EditorPanel(wxFrame* parent) :
    wxPanel(parent)
{
}
