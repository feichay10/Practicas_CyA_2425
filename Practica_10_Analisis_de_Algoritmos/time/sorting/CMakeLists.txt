cmake_minimum_required(VERSION 3.10)

project(sorting_library)

add_library(${PROJECT_NAME} SHARED
    src/bubble_sort.cpp
    src/merge_sort.cpp
    src/quick_sort.cpp
    src/shell_sort.cpp
)

add_library(sub::sorting_library ALIAS ${PROJECT_NAME}) 

target_include_directories( ${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)
