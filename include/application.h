#ifndef CHEM_TANK_MANAGER_APPLICATION_H_
#define CHEM_TANK_MANAGER_APPLICATION_H_

#include <QApplication>
#include "main_window.h"

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
