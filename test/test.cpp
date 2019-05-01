#include "application.hpp"

#include "gtest/gtest.h"

namespace {

int my_argc;
char **my_argv;

class ApplicationTest : public ::testing::Test {
  protected:
    ApplicationTest()  { }
    ~ApplicationTest() { }
    void SetUp() override { }
    void TearDown() override { }

    ctm::Application app{my_argc, my_argv};
};

TEST_F(ApplicationTest, createInitialWindow) { 
  app.mainWindow()->show();
  app.exec();
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  my_argc = argc;
  my_argv = argv;
  return RUN_ALL_TESTS();
}
 
} // namespace
