#include <headers.hpp>


//App start
wxIMPLEMENT_APP(App);

bool App::OnInit()
{
    if (!wxApp::OnInit())
        return false;
    //wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
    EditorFrame* frame = new EditorFrame("Minimal wxWidgets App");
    EditorPanel* mainPanel = new EditorPanel(frame);
    mainPanel->SetBackgroundColour(wxT("#4f5049"));
    wxBoxSizer* wBox = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* tBox = new wxBoxSizer(wxHORIZONTAL);

    EditorScrollWindow* mainWindow = new EditorScrollWindow(mainPanel);
    
    mainWindow->SetBackgroundColour(wxColor(47, 79, 79));

    //TODO: loop for adding textline to textBox sizer
    //like tBox->Add(textline, ???), the textline should not be senseable
    //about vertical chang but senseable about horizontal change. Need think by doing
    wBox->Add(mainWindow, 1, wxEXPAND | wxALL, 5);
    //wBox->Add(tBox);
    
    //mainWindow->SetSizer(tBox);
    mainPanel->SetSizer(wBox);
    mainWindow->SetScrollRate(1, 1);

    frame->Show(true);

    return true;
}