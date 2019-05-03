cmake_minimum_required(VERSION 3.1.0)

project(chem-tank-manager)

find_package(Qt5Widgets CONFIG REQUIRED)
find_package(Qt5Sql REQUIRED)

add_subdirectory(src)
add_subdirectory(test)

set_target_properties(demo PROPERTIES AUTOMOC ON)
set_target_properties(demo PROPERTIES AUTOUIC ON)
set_target_properties(demo PROPERTIES AUTOUIC_SEARCH_PATHS ../include)

target_include_directories(demo PRIVATE include)
