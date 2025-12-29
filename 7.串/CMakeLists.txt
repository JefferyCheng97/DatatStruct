add_executable(
    String
    src/my_string.cpp
    src/main.cpp
)

target_include_directories(
    String PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)