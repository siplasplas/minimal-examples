cmake_minimum_required(VERSION 3.5)

project(static-lib-res VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTORCC ON)

find_package(QT NAMES Qt5)
find_package(Qt5 COMPONENTS Widgets REQUIRED)

qt5_add_resources(QRC_SOURCES1 res/1.qrc)

add_subdirectory(lib)

set(PROJECT_SOURCES
        main.cpp
        MainWindow.cpp
        MainWindow.h
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} ${QRC_SOURCES1})

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets lib-for-example)