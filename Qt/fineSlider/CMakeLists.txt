cmake_minimum_required(VERSION 3.16)
project(fineSLider)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

set(SOURCE_FILES main.cpp
        MainWindow.cpp MainWindow.h
        FineSlider.cpp FineSlider.h)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets)
