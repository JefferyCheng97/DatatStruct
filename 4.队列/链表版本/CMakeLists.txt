add_executable(queue_linked
    src/main.cpp
)

target_include_directories(queue_linked 
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

