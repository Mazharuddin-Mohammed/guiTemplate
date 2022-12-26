#include"MainFrame.h"

#//Constructor with initializer list
MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size) : wxFeame(nullptr, wxID_ANY, title, pos, size){
    wxMenu* menuFile = new wxMenu;
    menuFile->Append(ID_HELLO, "&Hello...\tCtrl-H", "Help String Shown in Status Bar for this Menu Item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    wxMenu* menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuFile, "&Help");
    SetMenuBar(menuBar);

    CreateStatusBar();
    SetStatusText{"Welcome to GUITemplate"};
}

# Member event handlers definitions
void MainFrame::OnExit(wxCommandEvent& event){
    close(true);
}

void MainFrame::OnAbout(wxCommandEvent& event){
    wxMessageBox("This is GUITemplates's Hello People Example Sample", "About Hello People", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnHello(wxCommandEvent& event){
    wxLOGMESSAGE("Hello People from GUITemplate!")
}
