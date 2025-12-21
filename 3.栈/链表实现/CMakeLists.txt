add_executable(stack_linked
    src/main.cpp
)

target_include_directories(stack_linked PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

