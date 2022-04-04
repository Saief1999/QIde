cmake_minimum_required(VERSION 3.10)

project(QIde VERSION 0.1 LANGUAGES CXX C)
set(CMAKE_PREFIX_PATH "/home/ramizouari/Qt/6.2.3/gcc_64/lib/cmake")
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED  ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets LinguistTools REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets LinguistTools REQUIRED)

include_directories( gen )

#here
link_directories(gen)

add_custom_command(OUTPUT gen
        COMMAND mkdir -p gen
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "Create gen directory")

add_custom_command(OUTPUT ${CMAKE_SOURCE_DIR}/gen/java_lexer.c ${CMAKE_SOURCE_DIR}/gen/java_lexer.h
        COMMAND flex -o gen/java_lexer.c --header-file=gen/java_lexer.h java.l
        WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
        COMMENT "Generate java lexer")

add_custom_command(OUTPUT ${CMAKE_SOURCE_DIR}/gen/java_parser.c ${CMAKE_SOURCE_DIR}/gen/java_parser.h ${CMAKE_SOURCE_DIR}/gen/java_parser.output
        COMMAND bison -o gen/java_parser.c java.y -d -v -Wcounterexamples
        WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
        COMMENT "Generate java parser")

set(TS_FILES QIde_fr_FR.ts)

set(GENERATED_SOURCES gen/java_lexer.c gen/java_parser.c gen/java_parser.h gen/java_lexer.h)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.h mainwindow.cpp menubar.cpp
        maindocument.h maindocument.cpp
        sidebar.h sidebar.cpp
        tabholder.h tabholder.cpp
        bottombar.h bottombar.cpp
        compileoutput.h compileoutput.cpp
        ${TS_FILES}
)

#set(ADD_PARSER ON)
#if(${ADD_PARSER})
#    add_custom_command(OUTPUT gen/parser.c gen/lexer.c
#        COMMAND mkdir -p ${CMAKE_CURRENT_SOURCE_DIR}/gen
#        COMMAND flex -o ${CMAKE_CURRENT_SOURCE_DIR}/gen/java_lexer.c ${CMAKE_CURRENT_SOURCE_DIR}/java.l
#        COMMAND bison -o ${CMAKE_CURRENT_SOURCE_DIR}/gen/java_parser.c ${CMAKE_CURRENT_SOURCE_DIR}/java.y -d -v -Wcounterexamples)
#    set(GENERATED_SOURCES gen/parser.c gen/lexer.c)
#endif()

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(QIde
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES} ${GENERATED_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET QIde APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation

    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(QIde SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(QIde
            ${PROJECT_SOURCES}
        )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

target_link_libraries(QIde PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(QIde PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(QIde)
endif()
