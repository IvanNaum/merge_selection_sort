cmake_minimum_required(VERSION 3.23)
project(MergeSelectionSort C)

set(CMAKE_C_STANDARD 17)


set(HEADERS
        include/array.h)
set(SOURCES
        source/array.c)

include_directories(include)

add_executable(MergeSelectionSort
        ${HEADERS}
        ${SOURCES}
        main.c)
