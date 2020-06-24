#include "main.hpp"
#include "view.hpp"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

//App start
wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    if (!wxApp::OnInit())
        return false;
    //wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
    MyFrame* frame = new MyFrame("Minimal wxWidgets App");
    EDITOR_Panel* mainPanel = new EDITOR_Panel(frame);
    mainPanel->SetBackgroundColour(wxColor(47,79,79));
    wxScrolledWindow* scrl;

	scrl = new wxScrolledWindow(mainPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
    //sizer->Add(mainPanel, 1, wxEXPAND);

    //frame->SetSizer(sizer);
    //frame->SetAutoLayout(true);

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

    //bind eventhandler
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MyFrame::OnQuit, this, EDITOR_Quit);
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MyFrame::OnAbout, this, EDITOR_About);
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MyFrame::OnNew, this, EDITOR_New);
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MyFrame::OnSave, this, EDITOR_Save);
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MyFrame::OnSaveAs, this, EDITOR_SaveAs);

}

void MyFrame::OnNew(wxCommandEvent& WXUNUSED(event)){//TODO::
}
void MyFrame::OnSave(wxCommandEvent& WXUNUSED(event)) {//TODO::
}
void MyFrame::OnSaveAs(wxCommandEvent& WXUNUSED(event)) {//TODO::
}
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
