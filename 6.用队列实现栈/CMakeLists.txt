add_executable(
    QueueToStack
    src/main.cpp
)

target_include_directories(
    QueueToStack PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)