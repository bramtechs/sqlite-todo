cmake_minimum_required(VERSION 3.12)
project(sqlite_todo)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

## Main program

add_executable(${PROJECT_NAME}
  src/program.cc
  src/todo.hh
  src/todo_store.cc
  src/todo_store.hh
  src/iterator.hh
  src/todo_iterator.hh
  src/command.hh
  src/list_command.cc
  src/list_command.hh
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
  # change default working directory in Visual Studio to repository root.
  set_property(TARGET ${PROJECT_NAME} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")
  # change default starting project in Visual Studio
  set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT sqlite_todo)
endif()
