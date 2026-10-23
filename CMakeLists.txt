cmake_minimum_required(VERSION 4.1)

set(CMAKE_CXX_MODULE_STD ON)
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "451f2fe2-a8a2-47c3-bc32-94786d8fc91b")

project("labb1" CXX)

add_executable("labb1")

target_compile_features("labb1" PUBLIC cxx_std_23)

target_sources("labb1"
  PRIVATE
    "main.cpp"
  PRIVATE FILE_SET "modules" TYPE CXX_MODULES FILES
    "broken_class.cppm"
    "functions.cppm")

target_compile_options(labb1 PRIVATE /W4)