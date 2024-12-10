cmake_minimum_required(VERSION 3.10)

project(test_bench C CXX)

add_library(${PROJECT_NAME} SHARED
    src/test_bench.cpp
)

add_library(sub::test_bench ALIAS ${PROJECT_NAME}) 

target_include_directories( ${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(
    ${PROJECT_NAME}
    sub::sorting_library
) 