cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(gcc-poisoning-playground)

add_library(gccpoison INTERFACE IMPORTED)

set_property(
  TARGET gccpoison APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG
)

set_property(
  TARGET gccpoison APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE
)

set_target_properties(gccpoison PROPERTIES
  MAP_IMPORTED_CONFIG_MINSIZEREL Release
  MAP_IMPORTED_CONFIG_RELWITHDEBINFO Release
)

SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")

target_include_directories(gccpoison INTERFACE "${GCCPOISON_ROOT}")

add_executable(${PROJECT_NAME} 
    "src/main.cpp"
)

target_link_libraries(${PROJECT_NAME} gccpoison)