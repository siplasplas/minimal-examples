cmake_minimum_required(VERSION 3.5)

set(LIB_PROJECT_NAME lib-for-example)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTORCC ON)

find_package(QT NAMES Qt5)
find_package(Qt5 COMPONENTS Widgets REQUIRED)

qt5_add_resources(QRC_SOURCES2 res/2.qrc)

set(LIB_SOURCES
        LibWindow.cpp
        LibWindow.h)

add_library(${LIB_PROJECT_NAME} STATIC ${LIB_SOURCES} ${QRC_SOURCES2})

target_link_libraries(${LIB_PROJECT_NAME} PRIVATE Qt5::Widgets)