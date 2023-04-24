cmake_minimum_required(VERSION 3.23)
project(MergeSelectionSort C)

set(CMAKE_C_STANDARD 17)


set(HEADERS
        include/array.h
        include/selection_sort.h
        include/merge_sort.h
        include/is_sorted.h)
set(SOURCES
        source/array.c
        source/selection_sort.c
        source/merge_sort.c)

include_directories(include)

add_executable(MergeSelectionSort
        ${HEADERS}
        ${SOURCES}
        main.c)
