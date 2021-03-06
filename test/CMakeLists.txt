# download and unpack googletest at configure time
##################################################
configure_file(
	CMakeLists.txt.in 
	${CMAKE_CURRENT_BINARY_DIR}/googletest-download/CMakeLists.txt)

execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
	RESULT_VARIABLE result
	WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
	message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()

execute_process(COMMAND ${CMAKE_COMMAND} --build .
	RESULT_VARIABLE result
	WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
	message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# prevent overriding the parent project's compiler/linker settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# add googletest directly to our build 
# defines the gtest and gtest_main targets
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)
##################################################

set(TEST_FILES test.cpp)

list(REMOVE_ITEM SOURCE_FILES main.cpp)
list(TRANSFORM SOURCE_FILES PREPEND ${CMAKE_SOURCE_DIR}/src/)

# need to include header files for automoc feature to work
# if not, then automoc will not find headers unless located in same
# directory as source files
#add_executable(demo ${TEST_FILES} ${SOURCE_FILES} ${HEADER_FILES} ${FORMS})
add_executable(demo ${TEST_FILES} ${SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(demo Qt5::Widgets Qt5::Sql gtest gtest_main)
