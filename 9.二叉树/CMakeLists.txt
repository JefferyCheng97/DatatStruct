add_executable(
    BinaryTree
    src/main.cpp
)

target_include_directories(
    BinaryTree 
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)