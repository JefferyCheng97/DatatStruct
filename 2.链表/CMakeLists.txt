# 生成可执行文件
add_executable(LinkedList
    src/main.cpp
    src/delete.cpp
    src/insert.cpp
    src/update.cpp
    src/find.cpp
    src/print.cpp
)

# 包含头文件目录
target_include_directories(LinkedList
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include
)