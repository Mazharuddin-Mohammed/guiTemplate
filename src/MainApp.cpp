#include "MainApp.h"

wxIMPLEMENT_APP(MainApp);

bool MainApp::onInit(){
    MainFrame* frame = new MainFrame("Hello People", wxPoint(50,50), wxSize(450,340));
    frame->Show(true);
    return true;
}

