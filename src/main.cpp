#include "application.hpp"

int main(int argc, char **argv)
{
  ctm::Application app{argc, argv};  
  app.mainWindow()->show(); 
  return app.exec();
}
