#include "application.hpp"

namespace ctm {

Application::Application(int &argc, char **argv)
  : QApplication(argc, argv) 
{
  mainWin = new MainWindow();
}

Application::~Application() 
{
  if(mainWin) {
    delete mainWin;
  }
}

} // namespace ctm
