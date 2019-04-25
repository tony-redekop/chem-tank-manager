#ifndef CHEM_TANK_MANAGER_APPLICATION_HPP_
#define CHEM_TANK_MANAGER_APPLICATION_HPP_

#include <QApplication>

#include "main_window.hpp"

namespace ctm {

class Application : public QApplication 
{

  Q_OBJECT

  public:
    Application(int &argc, char **argv); 
    ~Application();

    MainWindow* mainWindow() { return mainWin; }

  private:
    MainWindow *mainWin;

};

} // namespace ctm

#endif // header guard
