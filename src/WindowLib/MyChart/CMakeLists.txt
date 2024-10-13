cmake_minimum_required(VERSION 3.14)

project(MyChart LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets Sql)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Charts)

add_library(MyChart SHARED
    MyChart_global.h
    mycharts.h
    mycharts.cpp
)
# 包含源文件目录，用于提升控件时可以找到源文件目录
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR})

target_link_libraries(MyChart PRIVATE Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(MyChart PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(MyChart PRIVATE Qt${QT_VERSION_MAJOR}::Charts)

target_compile_definitions(MyChart PRIVATE MYCHART_LIBRARY)
