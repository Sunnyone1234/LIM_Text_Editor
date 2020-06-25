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
    mainPanel->SetBackgroundColour(wxColor(47, 79, 79));

    EditorScrollWindow* mainWindow = new EditorScrollWindow(mainPanel);
    //sizer->Add(mainPanel, 1, wxEXPAND);

    //frame->SetSizer(sizer);
    //frame->SetAutoLayout(true);

    frame->Show(true);

    return true;
}