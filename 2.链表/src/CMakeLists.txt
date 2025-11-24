add_executable(LinkedList
    main.cpp
    delete.cpp
    insert.cpp
    update.cpp
    find.cpp
    print.cpp
)

target_include_directories(LinkedList
    PUBLIC ${CMAKE_SOURCE_DIR}/include)

message(STATUS "项目根目录路径: ${CMAKE_SOURCE_DIR}")