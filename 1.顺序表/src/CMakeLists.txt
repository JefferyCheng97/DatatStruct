# 生成可执行文件
add_executable(SequentialList
    main.cpp
    delete.cpp
    insert.cpp
    update.cpp
    find.cpp
    init.cpp
)

# 头文件所在目录
target_include_directories(SequentialList
    PUBLIC ${CMAKE_SOURCE_DIR}/include)


    