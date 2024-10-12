cmake_minimum_required(VERSION 3.23 FATAL_ERROR)

set(PROJECT_NAME Artwave)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOMOC ON)

project(${PROJECT_NAME})

add_subdirectory(src)
include_directories(src)

add_custom_target(
    run_python_module
    COMMAND ${CMAKE_COMMAND} -E env PYTHONPATH=${CMAKE_SOURCE_DIR}/src ${CMAKE_SOURCE_DIR}/venv/bin/python3 ${CMAKE_SOURCE_DIR}/src/python_module/main.py
)

#add_custom_target(
  #  run_all_python_modules
  #  COMMAND ${CMAKE_COMMAND} -E env PYTHONPATH=${CMAKE_SOURCE_DIR}/src ${CMAKE_SOURCE_DIR}/venv/bin/python3
  #python_module
#)
