add_executable(
    Tree
    src/main.cpp
)

target_include_directories(
    Tree PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)