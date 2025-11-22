cmake_minimum_required(VERSION 3.13)

# 项目名称
project(SequentialList LANGUAGES CXX)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)

# 添加可执行文件
add_executable(main main.cpp)