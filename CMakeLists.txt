cmake_minimum_required(VERSION 3.5)

project(QIde VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets LinguistTools REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets LinguistTools REQUIRED)

# Core Module Configuration START

set(LEX flex)

set(YACC bison)

set(CORE_DIR ${CMAKE_SOURCE_DIR}/QIde-core)

include_directories( QIde-core )

link_directories( QIde-core )

add_custom_command(OUTPUT ${CORE_DIR}/java_parser.cc ${CORE_DIR}/java_parser.hh ${CORE_DIR}/location.hh
        COMMAND ${YACC} -o java_parser.cc java_parser.yy
        WORKING_DIRECTORY "${CORE_DIR}"
        COMMENT "Generate java parser")

add_custom_command(OUTPUT ${CORE_DIR}/java_lexer.cc
        COMMAND ${LEX} -o java_lexer.cc java_lexer.ll
        WORKING_DIRECTORY "${CORE_DIR}"
        COMMENT "Generate java lexer")

set(CORE_SOURCES
        QIde-core/java_lexer.cc QIde-core/java_lexer.hh
        QIde-core/java_parser.cc QIde-core/java_parser.hh
        QIde-core/driver.cc QIde-core/driver.hh
        QIde-core/java_semantics.cc QIde-core/java_semantics.hh
        QIde-core/utils.hh
        QIde-core/location.hh
        QIde-core/java_lexer.ll
        QIde-core/java_parser.yy
        QIde-core/CodeGenerator.cpp QIde-core/CodeGenerator.h QIde-core/opcode.h QIde-core/opcode.cpp QIde-core/Instruction.cpp QIde-core/Instruction.h)


# Core Module Configuration END

set(TS_FILES QIde-gui/QIde_fr_FR.ts)

set(GUI_SOURCES
        QIde-gui/main.cpp
        QIde-gui/mainwindow.h QIde-gui/mainwindow.cpp QIde-gui/menubar.cpp
        QIde-gui/maindocument.h QIde-gui/maindocument.cpp
        QIde-gui/sidebar.h QIde-gui/sidebar.cpp
        QIde-gui/tabholder.h QIde-gui/tabholder.cpp
        QIde-gui/bottombar.h QIde-gui/bottombar.cpp
        QIde-gui/compileoutput.h QIde-gui/compileoutput.cpp
        ${TS_FILES}
        QIde-gui/syntax/JavaHighlighter.cpp QIde-gui/syntax/JavaHighlighter.h
        QIde-gui/error-handling/gui_error_handler.cc QIde-gui/error-handling/gui_error_handler.hh
        QIde-gui/LineNumberArea.cpp QIde-gui/LineNumberArea.h)

set(GUI_RESOURCES ${PROJECT_SOURCE_DIR}/QIde-gui/syntax/keywords ${PROJECT_SOURCE_DIR}/QIde-gui/syntax/defaultClasses ${PROJECT_SOURCE_DIR}/QIde-gui/syntax/defaultInterfaces)

set(PROJECT_SOURCES
        ${GUI_SOURCES}
        ${CORE_SOURCES}
)

# Copy Resources files to binary file directory
file(COPY ${GUI_RESOURCES} DESTINATION ${PROJECT_BINARY_DIR})


if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(QIde
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
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
