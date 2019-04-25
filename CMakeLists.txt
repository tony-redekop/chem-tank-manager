cmake_minimum_required(VERSION 3.1.0)

project(chem-tank-manager)

find_package(Qt5Core CONFIG REQUIRED)
#find_package(Qt5Widgets CONFIG REQUIRED)

add_subdirectory(src)

set_target_properties(app PROPERTIES AUTOMOC ON)
set_target_properties(app PROPERTIES AUTOUIC ON)

target_include_directories(app PRIVATE include)
