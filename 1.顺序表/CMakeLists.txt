cmake_minimum_required(VERSION 3.13)

# 项目名称
project(SequentialList LANGUAGES CXX)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 把 src 目录作为子目录加入
add_subdirectory(src)