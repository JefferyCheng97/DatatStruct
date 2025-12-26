add_executable(queue_sequential
    src/main.cpp
)

target_include_directories(queue_sequential 
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

