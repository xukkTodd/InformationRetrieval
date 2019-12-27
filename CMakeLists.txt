# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.0)

project ("IS_execise")

set (CMAKE_CXX_STANDARD 14)
set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set (LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

include_directories (${PROJECT_SOURCE_DIR})

# 包含子项目。
add_subdirectory ("src")

