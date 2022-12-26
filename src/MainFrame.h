#pragmaonce
#include<wx/wxprec.h>
#ifndef WX_PRECOMP
    #include<wx/wx.h>
#endif

enum{
    ID_HELLO = 1;
};

class MainFrame : public wxFrame{
    private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void onAbout(wxCommandEvent& event);
    wxDECLARE_EVENT_TABLE();
}

// Static Event Handler
wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_MENU(ID_HELLO, MainFrame::OnHello)
    EVT_MENU(wxID_EXIT, MainFrame::OnExit)
    EVT_MENU(wxID_ABOUT, MainFrame::OnAbout)
wxEND_EVENT_TABLE()
