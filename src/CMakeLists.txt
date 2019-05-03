set(SOURCE_FILES
    application.cpp
    main.cpp
    main_window.cpp
    )

set(HEADER_FILES
    main_window.h
    application.h
    connection.h
    )

set(FORMS
    main_window.ui
   )

list(TRANSFORM HEADER_FILES PREPEND ${CMAKE_SOURCE_DIR}/include/)

set(SOURCE_FILES ${SOURCE_FILES} PARENT_SCOPE)
set(HEADER_FILES ${HEADER_FILES} PARENT_SCOPE)
set(FORMS ${FORMS} PARENT_SCOPE)
