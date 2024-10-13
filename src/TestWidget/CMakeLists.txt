cmake_minimum_required(VERSION 3.14)

project(TestWidget LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets Sql)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Sql)

set(WindowLib ${CMAKE_SOURCE_DIR}/src/WindowLib)

include_directories(${WindowLib})

add_library(TestWidget SHARED
  TestWidget_global.h
  sqltest.h
  sqltest.cpp
  mdiwidget.h
  mdiwidget.cpp
  mdiwidget.ui
)
# 包含源文件目录，用于提升控件时可以找到源文件目录
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR})


target_link_libraries(TestWidget PRIVATE Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(TestWidget PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(TestWidget PRIVATE Qt${QT_VERSION_MAJOR}::Sql)

target_link_libraries(TestWidget PRIVATE ${CMAKE_SOURCE_DIR}/lib/libMyChart.dll.a)

target_compile_definitions(TestWidget PRIVATE TESTWIDGET_LIBRARY)
