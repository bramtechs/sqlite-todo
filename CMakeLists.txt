cmake_minimum_required(VERSION 3.12)
project(singleton_todo)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

## Main program

add_executable(${PROJECT_NAME}
  src/program.cc
  src/commands.hh
  src/todo_store.cc
  src/todo_store.hh
  src/iterator.hh
  src/todo_iterator.hh
)

## SQLITE library

target_sources(${PROJECT_NAME} PUBLIC
  vendor/sqlite3.c
)

target_include_directories(${PROJECT_NAME} PUBLIC
  vendor
)

## MISC - Integrated Development Environment

if (WIN32)
  # change default working directory in Visual Studio
  set_property(TARGET ${PROJECT_NAME} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")
endif()
