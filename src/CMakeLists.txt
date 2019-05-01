set(SOURCE_FILES
    application.cpp
    main.cpp
    main_window.cpp
    )

set(HEADER_FILES
    main_window.hpp
    application.hpp
    )

list(TRANSFORM HEADER_FILES PREPEND ${CMAKE_SOURCE_DIR}/include/)

set(SOURCE_FILES ${SOURCE_FILES} PARENT_SCOPE)
set(HEADER_FILES ${HEADER_FILES} PARENT_SCOPE)

# need to include header files for automoc feature to work
# if not, then automoc will not find headers unless they are located in same
# directory as source files
add_executable(app ${SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(app Qt5::Widgets)
