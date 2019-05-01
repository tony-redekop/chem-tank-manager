#include "application.hpp"
#include "connection.hpp"
#include <iostream>

#include <QSqlQuery>
#include <QDebug>

#include "gtest/gtest.h"

namespace {

int my_argc;
char **my_argv;

class ApplicationTest : public ::testing::Test {
  protected:
    ApplicationTest() {
      app.mainWindow()->show();
      app.exec();
    }
    ~ApplicationTest() { }
    void SetUp() override { }
    void TearDown() override { }

    ctm::Application app{my_argc, my_argv};
};

/*
TEST_F(ApplicationTest, createInitialWindow) { 
  app.mainWindow()->show();
  app.exec();
}
*/

/*
TEST_F(ApplicationTest, connectToDatabase) { 
  app.mainWindow()->show();
  app.exec();
  ASSERT_TRUE(ctm::createConnection());
}
*/

TEST_F(ApplicationTest, testQuery) {
  ctm::createConnection();
  QSqlQuery query("select * from T1");
  while(query.next()) {
    QString temperature{query.value(2).toString()};
    qDebug() << temperature;
  }
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  my_argc = argc;
  my_argv = argv;
  return RUN_ALL_TESTS();
}
 
} // namespace
