add_executable(
    StackToQueue
    src/main.cpp
)

target_include_directories(
    StackToQueue PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)