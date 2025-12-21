add_executable(stack_sequential
    src/main.cpp
)

target_include_directories(stack_sequential PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

