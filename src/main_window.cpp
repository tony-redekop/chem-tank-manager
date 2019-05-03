#include "main_window.h"
#include "ui_main_window.h"

namespace ctm {

MainWindow::MainWindow(QMainWindow *parent) 
  : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() {
  delete ui;
}

} // namespace ctm
