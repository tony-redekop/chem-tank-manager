#ifndef CHEM_TANK_MANAGER_MAIN_WINDOW_H_
#define CHEM_TANK_MANAGER_MAIN_WINDOW_H_

#include <QMainWindow>

namespace Ui {
  class MainWindow;
}

namespace ctm {

class MainWindow : public QMainWindow 
{

  Q_OBJECT

  public: 
    explicit MainWindow(QMainWindow *parent = nullptr);
    virtual ~MainWindow();
    
  public slots:
 
  signals:

  private:
    Ui::MainWindow *ui;
};

} // namespace ctm

#endif  // header guard
